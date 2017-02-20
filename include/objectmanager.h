#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H


class Random;
class ObjectManager
{
    public:
		enum EObject { EO_REVIVE, EO_BULLET, EO_LIFE, EO_TOTAL };

		ObjectManager();
        ~ObjectManager();

        void        generateObject(const bool);
        void        disable();
    
        EObject     getType();
        int         getPosition();
        bool        getAble();
    private:
        EObject     Type;
        int         Position;
        bool        Able;

}; 

#endif /* OBJECTMANAGER_H */

