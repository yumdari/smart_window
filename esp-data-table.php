<!DOCTYPE html>
<html>
<head>
    <meta charset = "UTF-8">
    <meta http-equiv="refresh" content = "30">
    <style type = "text/css">
    .spec{
        text-align:center;
    }
    .con{
        text-align:left;
    }
    </style>
</head>
<body>
    <h1 align = "center">Smart Window DB<h1>
    <div class = "spec">
        # <b>The sensor value description</b><br>
        <br>
    </div>

    <table border = '1' style = "width = 30%" align = "center">
    <tr align = "center">
        <th>ID</th>
        <th>Temp</th>
        <th>Humi</th>
        <th>Small</th>
        <th>Big</th>
        <th>Timetable</th>
        <
    </tr>
    <?php
        $conn = mysqli_connect("localhost", "root", "kcci");
        mysqli_select_db($conn, "esp_data");
        $result = mysqli_query($conn, "select * from SensorData order by reading_time desc");

        while($row = mysqli_fetch_array($result)){
        echo "<tr align = center>";
        echo '<td>'.$row['id'].'</td>';
        echo '<td>'.$row['temp'].'</td>';
        echo '<td>'.$row['humi'].'</td>';
        echo '<td>'.$row['small'].'</td>';
        echo '<td>'.$row['big'].'</td>';
        echo '<td>'.$row['reading_time'].'</td>';
        echo "</tr>";
        mysqli_close($conn);
        }
    ?>
    </table></body></html>
