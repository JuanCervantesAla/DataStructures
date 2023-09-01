#ifndef _MENU_HPP_
#define _MENU_HPP_

class Menu
{

private:
    int selectedOption;

public:
    int getSelectedOption() const;
    void setSelectedOption(const int&);
    void showMenu();

};


#endif // _MENU_HPP_
