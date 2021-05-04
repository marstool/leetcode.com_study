
all:

gs:
	nice -n 19     git status

up:
	nice -n 19     git push

ga:
	git add .

gcXmmm:=$(shell (LC_ALL=C date +"%Y%m%d_%H%M%p")|tr "/\r\n-" _)
gcX:=git_commit_X
$(gcX):=git_commit_with_date______current_dir_filesX
gcX :
	@echo
	nice -n 17 git commit -a -m $(gcXmmm)
	@echo

