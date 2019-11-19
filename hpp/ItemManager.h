#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

class Fire
{
    public:
    Fire();
    virtual ~ItemManager();
    int fireID = 1;

};

class ItemManager
{
    public:
        Fire fire;
        friend class Fire;
        ItemManager();
        virtual ~ItemManager();

    protected:

    private:
};



#endif // ITEMMANAGER_H
