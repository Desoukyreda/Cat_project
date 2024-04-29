<html lang="en">
<head>
  <meta charset="UTF-8">
</head>
<body>
  <h1><span>Student Record System </span></h1>
  <p>This project is a simple student record system implemented in C programming language. It allows Admin to perform basic operations such as adding, updating, deleting, and viewing student records and student to view and edit .</p>
  <h2>Description</h2>
  <p>This project consists of the following files:</p>
  <ul>
    <li><code>main.c</code>: Contains the main operation .</li>
    <li><code>admin.c</code>: Contains implementation of functions for admin.</li>
    <li><code>admin.h</code>: Header file for <code>admin.c</code>.</li>
    <li><code>student.c</code>: Contains implementation of functions for student.</li>
    <li><code>student.h</code>: Header file for <code>student.c</code>.</li>
    <li><code>common_fun.c</code>: Contains implementation of common functions .</li>
    <li><code>common_fun.h</code>: Header file for <code>common_fun.c</code>.</li>
    <li><code>README.md</code>: This file, contains information about the project.</li>
  </ul>
  <h2>Getting Started</h2>
  <p>To compile the project, navigate to the project directory and run:</p>
  <pre><code>gcc main.c Admin.c student.c common_fun.c -o myprogram</code></pre>
  <p>To run the compiled program, use:</p>
  <pre><code>./myprogram</code></pre>
<br>
  <h2>Usage</h2>
  <dl>
    <dt>Program have two mode : </dt>
    <dd> <dt>  1- Admin mode </dt>
    <dd>You can do some function on student record such (add ,remove,..) and save changes in file.txt .</dd>
    <dt> 2- Student mode </dt>
    <dd>You can do some function on your record such (view ,change (name,pass) ,..) .</dd>
   </dd>
  </dl>
 <br>
  <h2>Contributing</h2>
  <p>Feel free to contribute to this project.</p>
  <ol>
    <li>Fork the project.</li>
    <li>Create your feature branch (<code>git checkout -b feature/YourFeature</code>).</li>
    <li>Commit your changes (<code>git commit -am 'Add some feature'</code>).</li>
    <li>Push to the branch (<code>git push origin feature/YourFeature</code>).</li>
    <li>Create a new Pull Request.</li>
  </ol>
</body>
</html>
