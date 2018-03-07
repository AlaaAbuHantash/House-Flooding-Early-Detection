<?php
$servername = "fdb5.biz.nf";
$username = "2114886_alaa";
$password = "Aa_1861994";
$dbname = "2114886_alaa";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);


$sql = "SELECT ID, Distance FROM Flood";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
  while($row = $result->fetch_assoc()) {
        echo $row["ID"]." = ".$row["Distance"]." <br> ";
    }

}

 

$conn->close();

?>


