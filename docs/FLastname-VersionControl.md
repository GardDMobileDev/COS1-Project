# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

## [ C202610 ]

- **[ Desire White ]**
- **[ 10-04-2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ Ctrl + L]: Clear the Screen
- [ pwd]: Print the "Working Directory"
- [ ls]: List files and folders
- [ ls -a]: List files and folders, including invisible files
- [ ls -lah]: List all files and folders, in human readable form
- [ cd]: Change directory
- [ cd /]: Change directory, go to root directory
- [ cd ~]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../..]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

PS C:\Users\desire_white> cd C:\FS\COS1
PS C:\FS\COS1>

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Name & describe the three types of version control here.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

-[ [ git clone <repository-url>]: Clone a repository
- [ git config --global user.name "Your Name" ]: Set-up a global user name
- [ git config --global user.email "your-email@example.com" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add . ]: Add modified files to the next commit
- [ git commit -m "Your commit message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screenc

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

 [ git clone https://github.com/username/COS1.git
 [ cd COS1 ]
 [ git config --global user.name "Your Name" ]
 [ git config --global user.email "your-email@example.com" ]
 [ git status ]
 [ git add . ]
 [ git commit -m "Your commit message" ]: ]
 [ git log ]
 [git push ]


**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

  [What is the purpose of this file?
- This is important because the system should access your project but not other files 
- on your system you dont want accessed. I wouldnt want everyone to have access to my person files, like photos, passwords, other personal information etc.

  You can use [ git status ] to check and see what git has access to]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [Its not a part of the project that needs to be accessed, it contains information from
- the Finder settings. Unnecessary to be tracked and can cause system errors]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [ From github:
- You can list files/directories that you want to explicitely exclude from Git in a `.gitignore` file. This file should be placed at the root of your repository.

	It is noted that people usually exclude dependency caches, such as `node_modules`, system files, such as `.DS_Store`, among others]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[  "https://github.com/0nn0/git-basics-cheatsheet" and https://github.com/0nn0/terminal-mac-cheatsheet#english-version]

**Terminal Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Three Types of Version Control**  
[Site Address](https://www.someaddress.com/full/url/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://www.someaddress.com/full/url/)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.someaddress.com/full/url/)
