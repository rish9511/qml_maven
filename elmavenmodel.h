#ifndef ELMAVENMODEL_H
#define ELMAVENMODEL_H
#include <vector>

class EIC;

class ElMavenModel
{
    public:
        ElMavenModel();

        void addEic(EIC* eic) {
            eics.push_back(eic);
        }

        const std::vector<EIC*> getEics() { return eics; }

    private:
        std::vector<EIC*> eics;

};

#endif // ELMAVENMODEL_H
