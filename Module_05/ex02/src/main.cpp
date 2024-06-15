/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:05:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:28:18 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

int main() {
    {
        Bureaucrat b("Bob", 140);
        ShrubberyCreationForm s("home");
        RobotomyRequestForm r("robot");
        PresidentialPardonForm p("John");
        
        b.executeForm(s);
        b.signForm(s);
        b.executeForm(s);
        cout << endl;
        b.executeForm(r);
        b.signForm(r);
        b.executeForm(r);
        cout << endl;
        b.executeForm(p);
        b.signForm(p);
        b.executeForm(p);
    }
    cout << endl;
    {
        Bureaucrat b("Marvin", 1);
        RobotomyRequestForm r("Marvin");
        PresidentialPardonForm p("Arthur Dent");
        ShrubberyCreationForm s("Earth 2.0");

        b.executeForm(s);
        b.signForm(s);
        b.executeForm(s);
        cout << endl;
        b.executeForm(r);
        b.signForm(r);
        b.executeForm(r);
        cout << endl;
        b.executeForm(p);
        b.signForm(p);
        b.executeForm(p);
    }

    return 0;
}
