/*
** Score.hh for cpp_indie_studio
**
** Made by	Tanguy Lelievre
** Login	leliev_t
**
** Started on	Wed Jun 14 17:43:26 2017 Tanguy Lelievre
** Last update	Thu Jun 15 11:19:35 2017 Tanguy Lelievre
*/

#ifndef SCORE_HH_
#define SCORE_HH_

# include <vector>
# include <iostream>
# include <irrlicht.h>

class	Score
{
public:
  Score();

  void	addScore(irr::core::stringc, irr::s32);
  void	sort();
  irr::core::array<irr::s32>	getScores() const;
  irr::core::array<irr::core::stringc>	getPseudos() const;

private:
  irr::core::array<irr::s32>	_points;
  irr::core::array<irr::core::stringc>	_pseudos;
};

#endif /* !SCORE_HH_ */
