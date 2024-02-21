//
// Created by JoachimWagner on 20.02.2024.
//

#pragma once
#include <string>
#include <ostream>
#include <stdexcept>
namespace tiere {

    class Schwein {
    private:
        inline static const int INITIAL_WEIGHT{10};
        std::string name;
        int gewicht;
        void setGewicht(int gewicht) {
            Schwein::gewicht = gewicht;
        }
    public:


        explicit Schwein(const std::string &name = "Nobody") {
            setName(name);
            setGewicht(INITIAL_WEIGHT);
        }

        void fuettern(){
            setGewicht(getGewicht() + 1);
        }


        void setName(const std::string &name) {
            if(name == "Elsa") throw std::invalid_argument{"Ungueltiger Name"};
            Schwein::name = name;
        }
        // Generated Code
        int getGewicht() const {
            return gewicht;
        }
        const std::string &getName() const {
            return name;
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
