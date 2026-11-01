**why cmake ?**
cmake provide a automation we dont need to compile each file one by one 
or give big cmd like g++ pg1.c pg2.c pg3.c

most populer automation sw is make 

in make file we define or add what c/++ file we have to compile and wht they need it

so make file formate:- 

**#step 1**: default rule to build the target :  (# means comment)
all : output_file_name: #(a.out )

**#step2**: link object file
hellow: hellow.c
	gcc hello.c -o a.out

**#step3** : clean up file
clean:
	rm -f output_file_name

important tab require for evry under command like helllow: then enter and tab and then give build command
one more aftre clean command we give enter then tab and then rm -f outfile_name

but if increase the project size so make file also increase 
with that flags also increase means we can make file will become more complex


note* make file of linux kernal is 2082 lines long.

so can we automate the make file and make file automed the build

means two level of automations:- level 1:- automat make file and level 2 automate the build process
and now cmake come in picture for automate that both work.

cmake i think its create make but actually its cross- platform make file

cmake configure the **CMakeLists.txt**

**steps of cmake** 
**A** define you in project in CMakeLists.txt
**B** run CMake to create makefile
**C** build project useing make
**D** add code, fix things, jump to  step C
**E** if you add new file then jump to step A

tranditionally in make file are placed in the same directory as the source code 

but CMake is diffrent. the make file is generated in a diffrent directory.
	the cmakeLists.txt in source directory but automated generated makefile in diffrent directory 

cmake file is txt file 
where we mention :
**#step1**
CMake_minimum_required (VERSION 3.28.3)

**#step2**
project(projectname)

**#step3**
add_executable(output file name,sourcefilenmes.c , headerfilename.h)

thyen we have to create a build folder in project and inside of build we have to give cmake .. command then 
inside of build CMakeFiles folder created there multiple file autogenrated and make file also available

after that we have to give make cammnd and output file genearted

with the help of CMake we can build the files for others system not only make 
like ninja, visual studio

means same CMakeLists file we can use for other systems as well for generate the buld system


what are the main diffrence bw ninja and GNU

**1**. gnu and ninja both are build system

**2**. for gnu we use makefile and ninja we have use build.ninja

**3**. makefile we have to write manually and but ninja mostlt auto generated via CMake

**4**. makefile use for large project and ninja is very good for large projects

ninja use is chromium browser where 30000 source files



ninja replace make

CMakeList file same as its

only in build folder we have to give command :- **cmake -G ninja ..**
then ninja build ready

then output file genearted 
for file execution we have give only **ninja** command in GNU we use make command




















