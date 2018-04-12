#black-box-test-input-generator
<b>This project has been coded in C++</b>
<h2>Setup</h2>
<ul>
<b>In order to execute the code on your system:</b>
<li>Append path of GCC 4.8 by using the following statement: export PATH=/usr/local/gcc/bin:$PATH</li>
<li>Append the PATH variable with the path of the MPC file on your system
<ul>
<li>Navigate into the MPC folder</li>
<li>Execute the statement (Insert your username): export MPC_ROOT=/home/username/MPC</li>
<li>Add the path to the global namespace: export PATH=$PATH:$MPC_ROOT</li>
<li>Give permissions to access mwc.pl file: chmod +x mwc.pl</li>
</ul>
</li>
<li>Get into the assignment's folder and execute the statement: mwc.pl -type make -features cpp11=1</li>
<li>Execute the command: make</li>
<li>Run the project with the command: ./assignment1</li>
</ul>
<ul>
<b>In order to execute the code on Windows:</b>
<li>In the command prompt navigate to the assignment's folder</li>
<li>Execute the statement (vc11 is for Visual Studio 2012): mwc.pl -type vc11</li>
<li>Double click on the assignment1.sln file and use the Visual Studio Debugger to run the code</li>
</ul>
<h2>Execution</h2>
<ol start=1>
<b>The testing techniques are as shown below:</b>
<li>Boundary Value Analysis</li>
<li>Worst-Case Robustness</li>
<li>Weak Normal Equivalence Class</li>
<li>Weak Robust Equivalence Class</li>
</ol>
<ul><b>Please enter the number of the testing technique you would want to run</b></ul>
<ul>
<b>Then, for types 1 and 2:</b>
<li>Please enter the number of input variables</li>
<li>Then, please enter the range for each variable on a separate line</li>
</ul>
<ul>
<b>For types 3 and 4:</b>
<li>Please enter the number of input variables</li>
<li>Then, please enter the partitions for each variable on a separate line (all partitions for one variable must be on the same line)</li>
</ul>
