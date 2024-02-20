//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once
#include <string>
#include <ostream>
#include <stdexcept>
namespace tiere {

    class Schwein {
        std::string name;
        int gewicht;
        void setGewicht(int gewicht) {
            Schwein::gewicht = gewicht;
        }
    public:
        explicit Schwein(const std::string &name = "Nobody") {
            setName(name);
            setGewicht(10);
        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            if(name == "Elsa") throw std::invalid_argument{"Ungueltiger Name"};
            Schwein::name = name;
        }

        int getGewicht() const {
            return gewicht;
        }

        friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
            os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
            return os;
        }

        bool operator==(const Schwein &rhs) const {
            return name == rhs.name &&
                   gewicht == rhs.gewicht;
        }

        bool operator!=(const Schwein &rhs) const {
            return !(rhs == *this);
        }
    };

}
