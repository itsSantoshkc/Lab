<?php
   class Book {
   

      var $title;

      /*Constructor*/
      function __construct($param1) {
         $this->title = $param1;
   
      }

 
      function getTitle(){
         echo "Title: $this->title \n";
         echo "<br>";
      }

      function __destruct(){
         echo "Exit from the book class\n";
      }
   }

   $b1 = new Book("Constructor");
   $b1->getTitle();
?>