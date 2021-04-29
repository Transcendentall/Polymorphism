#include <iostream>

using namespace std;



class Pizza
{
private:


public:

        virtual int costofpizza() = 0;

        void write()
        {
            cout << endl;
            cout << "          ПИЦЦА" << endl;
            cout << endl;
            cout << "Название           : " << this->name << endl;
            cout << "Описание           : " << this->description << endl;
            cout << "Размер             : " << this->sizep << endl;
            cout << "Раз посолено       : " << this->nsalt << endl;
            cout << "Раз добавлено сыра : " << this->mcheese << endl;
            cout << "Стоимость          : " << this->cost << endl;
            cout << "================================" << endl;
            cout << endl;
        }

        void prochieharacteristiki()
        {
            while ((this->sizep!=25) && (this->sizep!=30) && (this->sizep!=35) && (this->sizep!=40))
            {
            cout << "Введите размер пиццы. На выбор есть варианты 25, 30, 35, 40:" << endl;
            cin >> this->sizep;
                if ((this->sizep!=25) && (this->sizep!=30) && (this->sizep!=35) && (this->sizep!=40))
            {
            cout << "Вы что-то не то ввели. Попробуйте снова..." << endl;
            }
            }
            cout << "Введите, сколько раз вы хотите посолить вашу пиццу (если не хотите добавлять, введите 0):" << endl;
            cin >> this->nsalt;
            cout << "Введите, сколько раз вы хотите добавить сыра в вашу пиццу (если не хотите добавлять, введите 0):" << endl;
            cin >> this->mcheese;
            costofpizza();


        }


        std::string getname()
            {
                return this->name;
            }
            std::string getdescription()
            {
                return this->description;
            }
            unsigned short int getsizep()
            {
                return this->sizep;
            }
            unsigned int getcost()
            {
                return this->cost;
            }
            unsigned short int getnsalt()
            {
                return this->nsalt;
            }
            unsigned short int getmcheese()
            {
                return this->mcheese;
            }

protected:

        std::string name = "";
        std::string description = "";
        unsigned short int sizep = 0;
        unsigned int cost = 0;
        unsigned short int nsalt = 0;
        unsigned short int mcheese = 0;

};

class PizzaRegina : public Pizza
{
private:


public:

        PizzaRegina()
        {
            this->name = "Pizza Regina";
            this->description = "Пицца с помидорами, моцареллой, шампиньонами, ветчиной, орегано (иногда ещё и с чёрными оливками).";
            prochieharacteristiki();
        }

        int costofpizza() override
        {
            this->cost = 100 + (3*this->sizep) + (this->sizep*this->nsalt) + (3*this->sizep*this->mcheese);
            cout << "Стоимость вашей пиццы = " << this->cost;
            return this->cost;
        }

protected:

};

class PizzaDiabola : public Pizza
{
private:


public:

        PizzaDiabola()
        {
            this->name = "Pizza Diabola";
            this->description = "Пицца с салями и острым калабрийским перцем.";
            prochieharacteristiki();
        }

        int costofpizza() override
        {
            this->cost = 666 + this->sizep + 2*this->sizep*this->nsalt + this->sizep*this->mcheese;
            cout << "Стоимость вашей пиццы = " << this->cost;
            return this->cost;
        }

protected:

};

class PizzaHawaii : public Pizza
{
private:


public:

        PizzaHawaii()
        {
            this->name = "Pizza Hawaii";
            this->description = "Пицца с ветчиной и ананасом.";
            prochieharacteristiki();
        }

        int costofpizza() override
        {
            this->cost = 225 + this->sizep*5 + this->sizep*(this->nsalt+this->mcheese);
            cout << "Стоимость вашей пиццы = " << this->cost;
            return this->cost;
        }

protected:

};

class PizzaConLeCozze : public Pizza
{
private:


public:

        PizzaConLeCozze()
        {
            this->name = "Pizza con le cozze";
            this->description = "Пицца с мидиями, чесноком, оливковым маслом и петрушкой.";
            prochieharacteristiki();
        }

        int costofpizza() override
        {
            this->cost = 300 + this->sizep*10 + 2*(this->sizep+this->nsalt) + 2*(this->sizep+this->mcheese);
            cout << "Стоимость вашей пиццы = " << this->cost;
            return this->cost;
        }

protected:

};

class SicilianPizza : public Pizza
{
private:


public:

        SicilianPizza()
        {
            this->name = "Sicilian pizza";
            this->description = "Квадратная пицца с анчоусами.";
            prochieharacteristiki();
        }

        int costofpizza() override
        {
            this->cost = this->sizep*15 + 2*(this->sizep+this->nsalt) + 2*(this->sizep+this->mcheese) + 2*(this->sizep+this->nsalt+this->mcheese);
            cout << "Стоимость вашей пиццы = " << this->cost;
            return this->cost;
        }

protected:

};

struct PizzaInfo
{
    std::string name = "";
    std::string description = "";
    unsigned short int sizep = 0;
    unsigned int cost = 0;
    unsigned short int nsalt = 0;
    unsigned short int mcheese = 0;
};

int main()
{
    int pizzatype = -1;
    int actiontype = -1;
    int i=0;
    PizzaInfo pizzacount[100];

    while (actiontype!=2)
    {
    while ((actiontype!=1) && (actiontype!=2))
    {
    cout << "Выберите действие. Введите:" << endl;
    cout << " 1 - если хотите добавить новую пиццу в заказ;" << endl;
    cout << " 2 - если хотите распечатать свой заказ (даже если он пустой)." << endl;
    cin >> actiontype;
    if ((actiontype!=2) && (actiontype!=1))
            {
            cout << "Вы что-то не то ввели. Попробуйте снова..." << endl;
            }
    }
    if (actiontype==1)
    {

    while ((pizzatype != 1) && (pizzatype != 2) && (pizzatype != 3) && (pizzatype != 4) && (pizzatype != 5))
    {
            cout << "Выберите тип пиццы. Введите:" << endl;
            cout << " 1 - если хотите Pizza Regina;" << endl;
            cout << " 2 - если хотите Pizza Diabola;" << endl;
            cout << " 3 - если хотите Pizza Hawaii;" << endl;
            cout << " 4 - если хотите Pizza con le cozze;" << endl;
            cout << " 5 - если хотите Sicilian pizza." << endl;
            cin >> pizzatype;
            if ((pizzatype != 1) && (pizzatype != 2) && (pizzatype != 3) && (pizzatype != 4) && (pizzatype != 5))
            {
            cout << "Вы что-то не то ввели. Попробуйте снова..." << endl;
            }
    }
    if (pizzatype == 1)
    { Pizza* P1 = new PizzaRegina();
    pizzacount[i].name = P1->getname();
    pizzacount[i].description = P1->getdescription();
    pizzacount[i].cost = P1->getcost();
    pizzacount[i].mcheese = P1->getmcheese();
    pizzacount[i].nsalt = P1->getnsalt();
    pizzacount[i].sizep = P1->getsizep();
    cout << "Отлично! Вы добавили новую пиццу..." << endl;
    P1->write();
    delete P1;
    ++i;}
    if (pizzatype == 2)
    { Pizza* P1 = new PizzaDiabola();
    pizzacount[i].name = P1->getname();
    pizzacount[i].description = P1->getdescription();
    pizzacount[i].cost = P1->getcost();
    pizzacount[i].mcheese = P1->getmcheese();
    pizzacount[i].nsalt = P1->getnsalt();
    pizzacount[i].sizep = P1->getsizep();
    cout << "Отлично! Вы добавили новую пиццу..." << endl;
    P1->write();
    delete P1;
    ++i;}
    if (pizzatype == 3)
    { Pizza* P1 = new PizzaHawaii();
    pizzacount[i].name = P1->getname();
    pizzacount[i].description = P1->getdescription();
    pizzacount[i].cost = P1->getcost();
    pizzacount[i].mcheese = P1->getmcheese();
    pizzacount[i].nsalt = P1->getnsalt();
    pizzacount[i].sizep = P1->getsizep();
    cout << "Отлично! Вы добавили новую пиццу..." << endl;
    P1->write();
    delete P1;
    ++i;}
    if (pizzatype == 4)
    { Pizza* P1 = new PizzaConLeCozze();
    pizzacount[i].name = P1->getname();
    pizzacount[i].description = P1->getdescription();
    pizzacount[i].cost = P1->getcost();
    pizzacount[i].mcheese = P1->getmcheese();
    pizzacount[i].nsalt = P1->getnsalt();
    pizzacount[i].sizep = P1->getsizep();
    cout << "Отлично! Вы добавили новую пиццу..." << endl;
    P1->write();
    delete P1;
    ++i;}
    if (pizzatype == 5)
    { Pizza* P1 = new SicilianPizza();
    pizzacount[i].name = P1->getname();
    pizzacount[i].description = P1->getdescription();
    pizzacount[i].cost = P1->getcost();
    pizzacount[i].mcheese = P1->getmcheese();
    pizzacount[i].nsalt = P1->getnsalt();
    pizzacount[i].sizep = P1->getsizep();
    cout << "Отлично! Вы добавили новую пиццу..." << endl;
    P1->write();
    delete P1;
    ++i;}
    pizzatype=-1;
    actiontype=-1;

    cout << endl;

    }

    }

    if (i>0)
    {

    cout << "______________________________________" << endl;
    cout << "          ИТАК, ВАШ СПИСОК ПИЦЦ :     " << endl << endl;
    unsigned long long res = 0;
    for (int j=0; j<i; ++j)
    {
            cout << endl;
            cout << " ПИЦЦА НОМЕР " << j+1 << " : " << endl;
            cout << endl;
            cout << "Название           : " << pizzacount[j].name << endl;
            cout << "Описание           : " << pizzacount[j].description << endl;
            cout << "Размер             : " << pizzacount[j].sizep << endl;
            cout << "Раз посолено       : " << pizzacount[j].nsalt << endl;
            cout << "Раз добавлено сыра : " << pizzacount[j].mcheese << endl;
            cout << "Стоимость          : " << pizzacount[j].cost << endl;
            cout << "++++++++++++++++++++++++++++++++++++" << endl;
            cout << endl;
            res=res+pizzacount[j].cost;
    }
            cout << endl;
    cout << "ИТОГОВАЯ СТОИМОСТЬ ВСЕГО ЗАКАЗА: " << res << endl << endl << endl;
            cout << "================================" << endl;
    }
    else
    {
    cout << "Ваш список пицц пуст. Очень жаль..." << endl;
    }
    return 0;
}
