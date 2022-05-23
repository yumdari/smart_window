<!DOCTYPE html>
<html><body>
<?php
/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-mys>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

$servername = "localhost";

// REPLACE with your Database name
$dbname = "esp_data";
// REPLACE with Database user
$username = "root";
// REPLACE with Database user password
$password = "kcci";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT id, sensor, location, temp, humi, value3, reading_time FROM >

echo '<table cellspacing="5" cellpadding="5">
      <tr>
        <td>ID</td>
        <td>Sensor</td>
        <td>Location</td>
        <td>Temp</td>
        <td>Humi</td>
        <td>Value 3</td>
        <td>Timestamp</td>
      </tr>';

if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_sensor = $row["sensor"];
        $row_location = $row["location"];
        $row_temp = $row["temp"];
        $row_humi = $row["humi"];
        $row_value3 = $row["value3"];
        $row_reading_time = $row["reading_time"];
        // Uncomment to set timezone to - 1 hour (you can change 1 to any numbe>
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time >

        // Uncomment to set timezone to + 4 hours (you can change 4 to any numb>
        //$row_reading_time = date("Y-m-d H:i:s", strtotime("$row_reading_time >

        echo '<tr>
                <td>' . $row_id . '</td>
                <td>' . $row_sensor . '</td>
                <td>' . $row_location . '</td>
                <td>' . $row_temp . '</td>
                <td>' . $row_humi . '</td>
                <td>' . $row_value3 . '</td>
                <td>' . $row_reading_time . '</td>
              </tr>';
    }
    $result->free();
}

$conn->close();
?>
</table>
</body>
</html>

