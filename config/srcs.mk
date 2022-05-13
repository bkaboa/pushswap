PMAINP		=	main/
PUTILSP		=	utils/
PSTRUCT		=	$(PMAINP)struct/
PPARSING	=	$(PMAINP)parsing/
PSORT		=	$(PMAINP)first_sort/
POPERATOR	=	$(PMAINP)operator/
PALGO		=	$(PMAINP)algo/

#$(PALGO)sort.c
SRCS	=	$(PMAINP)pushswap.c					\
			$(PMAINP)first_sort.c				\
			$(PSTRUCT)struct.c					\
			$(PPARSING)parsing.c				\
			$(PPARSING)print_error.c			\
			$(POPERATOR)operator.c				\
			$(POPERATOR)operator2.c				\
			$(POPERATOR)operator3.c				\
			$(PALGO)algo_utils.c				\
			$(PALGO)sort_under_10.c				\
			$(PALGO)sort.c						\
			$(PUTILSP)split.c					\
			$(PUTILSP)small_utils.c				\
			$(PUTILSP)small_utils2.c
