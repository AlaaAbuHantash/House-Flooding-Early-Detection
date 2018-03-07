
<!DOCTYPE html>
<html>
<body>

<h1>Hello </h1>
<h2>This is alaa and abrar website =D </h2>
</body>
</html>


<?php
$servername = "fdb5.biz.nf";
$username = "2114886_alaa";
$password = "Aa_1861994";
$dbname = "2114886_alaa";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
echo "Connected successfully =D ";
echo "<br>";

$sql = "SELECT ID, Distance FROM Flood";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table><tr><th>ID</th><th>distance</th></tr>";
   
  while($row = $result->fetch_assoc()) {
        echo "<tr><td>".$row["ID"]."</td><td>".$row["Distance"]."</td></tr>";
    }

    echo "</table>";

}
else {
    echo "0 results";
}

echo "<br>";
echo "<br>";
echo "<br>";

$Dist = $_GET["Dist"];
$ID = $_GET["ID"];
$sql = "UPDATE Flood SET Distance=$Dist WHERE ID=$ID";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

echo "<br>";
echo "<br>";
echo "<br>";

$sql = "SELECT ID, Distance FROM Flood";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<table><tr><th>ID</th><th>distance</th></tr>";
   
  while($row = $result->fetch_assoc()) {
        echo "<tr><td>".$row["ID"]."</td><td>".$row["Distance"]."</td></tr>";
    }

    echo "</table>";

}else {
    echo "0 results";
}   

$conn->close();

?>


