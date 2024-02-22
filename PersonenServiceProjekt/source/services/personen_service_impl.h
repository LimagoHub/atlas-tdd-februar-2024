//
// Created by JoachimWagner on 21.02.2024.
//

#pragma once
#include "../persistence/personen_repository.h"
#include "personen_service.h"
#include "blacklist_service.h"
#include "personen_service_exception.h"

class personen_service_impl :public personen_service{


public:


    personen_service_impl(personen_repository &repo, blacklist_service &blacklistService) :
        repo(repo),
        blacklistService(blacklistService) {}

    /*
 *	Vorname < 2 -> PSE
 *	Nachname < 2 -> PSE
 *
 *	Attila -> PSE
 *
 *	Alle technische Exceptions -> PSE
 *
 *	Happy Day -> person an Save_or_update Methode uebergeben
 *
 */
    void speichern(person &person_)   override{
        try {
            speichernImpl(person_);

        } catch(const personen_service_exception &ex) {
            throw ex;
        }
        catch(std::exception &ex) {
            throw personen_service_exception{"Ein Fehler ist aufgetreten"};
        }

    }

    void speichern(std::string vorname, std::string nachname) override {
        const std::string uuid = "afe3183f-2e7a-48bb-9113-ac34cb0b40ae";
        person p{vorname, nachname};
        p.setId(uuid);
        speichern(p);
    }
private:

    personen_repository &repo;
    blacklist_service &blacklistService;
    void speichernImpl(const person &person_) const {
        check_person(person_);
        repo.save_or_update(person_);
    }

    void check_person(const person &person_) const {
        validate_person(person_);
        business_check(person_);
    }

    void business_check(const person &person_) const {
        if (blacklistService.is_blacklisted(person_))
            throw personen_service_exception{"Unerwuenschte Person"};
    }

    void validate_person(const person &person_) const {
        if (person_.getVorname().length() < 2)
            throw personen_service_exception{"Vorname zu kurz"};
        if (person_.getNachname().length() < 2)
            throw personen_service_exception{"Nachname zu kurz"};
    }
};
