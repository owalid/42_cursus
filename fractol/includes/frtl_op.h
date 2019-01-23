#ifndef FRTL_OP_H
# define FRTL_OP_H
# include "frtl.h"

t_frtlop	g_frtlop[] =
{
	{1, &frtl_dspl_mand},
	{2, &frtl_dspl_ju},
	{3, &frtl_dspl_budbrot},
	{0, &frtl_dspl_mand}
};

#endif
