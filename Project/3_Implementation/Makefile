Project_Name = Smart_Vacuum_cleaner
SRC = firmware.c 

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

Build:
	gcc	$(SRC)	-o	$(call Fixpath,$(Project_Name).$(EXEC))	-lm
run:Build
	./$(SRC)	-o	$(call Fixpath,$(Project_Name).$(EXEC))

Build_test:
	gcc	$(TEST_SRC)	-o	$(call Fixpath,$(Project_Name).$(EXEC))	-lm
run:Build_test
	./$(SRC)	-o	$(call Fixpath,$(Project_Name).$(EXEC))
	
