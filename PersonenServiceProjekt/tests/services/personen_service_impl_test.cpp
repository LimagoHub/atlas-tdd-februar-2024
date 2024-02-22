//
// Created by JoachimWagner on 21.02.2024.
//

#include "personen_service_impl_test.h"
#include <stdexcept>

TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throws_personen_service_exception) {
    try {
        // Arrange
        person invalidPerson{"J", "Doe"};
        EXPECT_CALL(repositoryMock, save_or_update(invalidPerson)).Times(0);
        // Act
        objectUnderTest.speichern(invalidPerson);
        // Assertion
        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Vorname zu kurz"));
    }
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throws_personen_service_exception) {
    try {
        // Arrange
        person invalidPerson{"John", "D"};
        EXPECT_CALL(repositoryMock, save_or_update(invalidPerson)).Times(0);
        // Act
        objectUnderTest.speichern(invalidPerson);
        // Assertion
        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Nachname zu kurz"));
    }
}

TEST_F(personen_service_impl_test, speichern__Unerwuenschte_Person__throws_personen_service_exception) {
    try {
        InSequence sequence;
        // Arrange
        person anyPerson{"John", "Doe"};
        EXPECT_CALL(blacklistServiceMock, is_blacklisted(anyPerson)).WillOnce(Return(true));
        EXPECT_CALL(repositoryMock, save_or_update(anyPerson)).Times(0);
        // Act
        objectUnderTest.speichern(anyPerson);
        // Assertion
        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Unerwuenschte Person"));
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_blacklist_service__throws_personen_service_exception) {
    try {
        InSequence sequence;
        // Arrange
        person anyPerson{"John", "Doe"};
        EXPECT_CALL(blacklistServiceMock, is_blacklisted(anyPerson)).WillOnce(Throw(std::invalid_argument{"Upps"}));
        EXPECT_CALL(repositoryMock, save_or_update(anyPerson)).Times(0);
        // Act
        objectUnderTest.speichern(anyPerson);
        // Assertion
        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Ein Fehler ist aufgetreten"));
    }
}


TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_service__throws_personen_service_exception) {
    try {
        // Arrange
        person validPerson{"John", "Doe"};

        EXPECT_CALL(repositoryMock,save_or_update(_)).WillOnce(Throw(std::invalid_argument{"upps"}));
        // Act
        objectUnderTest.speichern(validPerson);
        // Assertion
        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Ein Fehler ist aufgetreten"));

    }
}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo) {

    InSequence sequence;
    // Arrange
    person validPerson{"John", "Doe"};

    EXPECT_CALL(blacklistServiceMock, is_blacklisted(validPerson)).WillOnce(Return(false));
    EXPECT_CALL(repositoryMock, save_or_update(validPerson));
    // Act
    objectUnderTest.speichern(validPerson);
    // Assertion
}


TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo_overloaded) {


    // Arrange
    person captured_person{};

    EXPECT_CALL(blacklistServiceMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repositoryMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));
    // Act
    objectUnderTest.speichern("John","Doe");

    // Assertion
    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));



}

void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistServiceMock, is_blacklisted(_)).WillByDefault(Return(false));
}
