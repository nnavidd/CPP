/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:56:22 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:52:31 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm("ShrubberyCreationForm", 145, 137), _target("No target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if(this != &other){
		//since the all attributes of AForm supposed to remained private, doesn't need to call AForm::operator= here
		// AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (checkRequirements(executor)) {
		std::ofstream file((this->getName() + "_shrubbery").c_str());
		// std::ofstream file(_target + "_shrubbery");
		if (file.is_open() == false)
			throw FileOpenFailed();
		file 	<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWNNNK0KNNXXKXNNNNNWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWNXNNxlkOl;;cxOl;xX0ol0WNNNWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWNWWNXXK0dd:,ldd;,,,;ldxc'cdxKKXNNNWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWNK0Oxl,.'.,clo:,:::;,...'cdoOXKNWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWXxlxOdO0o:;'''.,:;',::,.,,..,:o00dkOoxXWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWNKx:,,':ccl,',::;::''::,.,;,.'cdlc',,;xKWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWXk0kc;;,,ll'..;:;:;..'..''''';ox:';,ckl:kNWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWNKOo:,cc,.:o;.....:d'.,,'..:l,;;'.,c:,,':ONKXWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWXd::c;.','',:c:....':'...;;;:'..''''..'clclo0NWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWNKXKkkolxl..cc;':l;';c:,..,cl,...';:cl;.,clc''dKKXWWNWWWWWWWW" << std::endl
				<< "WWWWWWWWWNKKkcc:.cl'':,.,oc,,,,lk:';'.'.:c',;,;;,cc:oc;o0KXWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWNXkl;::,;lc:;:c;'lc:oc:d:;o:,ll;,:;;',;,;...'c;ckKNWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWXk:;dxc'.'cc,,ll,.,:o0kc..';:'.:c;,:;'::'..',:;,:xXWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWNX0Oo;od::;..':;,;;';kKk,..;o:ld'..,,;,'':dl',dKNWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWKkx;.';;;'.'',::;ll'.lK0:..';:l:;c;,cooo:;,;clx0XWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWXx;:dl::lxc..,c::xkxo;.''. .lkKXKkc;clc:l:;dkl;;dKNWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWNNKXNXNNKk:,o0KxOWWWWNO,.  ,OWWWNNOx0kc':dOXN0OKNWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWNNXKNWNNWWWWWWWx.   ,0WWWWWWNWNKXNNNNWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW0:.  .,kNWNWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWNWWWWWWWWWWWk.  .;0NWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWXO0KXWWWNKc.  .oNWWWNWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWNNNWKx;.lx0WNNK:... 'OWNWNNXKKNWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWW0llxd:..lxk00Ol.    :000KNXl;oxO0KNWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWNN0l:clc..lxdddc.     .colcdk:'ll;:dOXXWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWNWXOxc::cc..loll;.       .'.'cl,'ll;;oxk0WWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWNNNNKOko;,'.',,...'...         ...',...'.';;,cxO0XNNNNWWWWWWWW" << std::endl
				<< "WWWWWWWNXKKKxlc:;,''......   .     .      .......',,;;:odOXXXNWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWNNNNNXK00Okxxxolodl::cc:cccllloxxxkO000XXXNWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNNNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl
				<< "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl;
		file.close();
		std::cout << GREEN << _target << ORG " drew an Tree in a file inside the current folder!" RESET << std::endl;
	}

}
