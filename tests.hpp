/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:57:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/21 15:49:05 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H

#include <cstdlib>
#include <vector>
#include <fstream>
#include "./containers/vector.hpp"

#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[1;31m"
#define KGRN  "\x1B[1;32m"
#define KYEL  "\x1B[1;33m"
#define KBLU  "\x1B[1;34m"
#define KMAG  "\x1B[1;35m"
#define KCYN  "\x1B[1;36m"
#define KWHT  "\x1B[1;37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define UNDL(x) "\x1B[4m" x RST

#endif  /* _COLORS_ */

void    compareFilesOutput( void );

bool    testVectorConstructors( void );

void    testVectorConstructorAll(void);
void    testVectorDefaultConstructor(bool isStd, std::string ns, bool all);
void	testVectorFillConstructor(bool isStd, std::string ns, bool all);
void	testVectorRangeConstructor(bool isStd, std::string ns, bool all);
void	testVectorCopyConstructor(bool isStd, std::string ns, bool all);
void	testVectorOperatorEqual(bool isStd, std::string ns, bool all);


bool	testVectorIterators(void);

void    testVectorIteratorAll( void );
void    testVectorIteratorBegin( bool isStd, std::string ns, bool all );
void    testVectorIteratorEnd( bool isStd, std::string ns, bool all );
void    testVectorIteratorRbegin( bool isStd, std::string ns, bool all );
void    testVectorIteratorRend( bool isStd, std::string ns, bool all );

bool    testVectorCapacity( void );

void    testVectorSize( bool isStd, std::string ns, bool all );
void    testVectorMaxSize( bool isStd, std::string ns, bool all );
void    testVectorResize( bool isStd, std::string ns, bool all );


#endif