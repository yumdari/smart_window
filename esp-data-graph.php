<?php
$conn = mysqli_connect("localhost", "root", "kcci");
mysqli_set_charset($conn, "utf8");
mysqli_select_db($conn,"esp_data");
$result = mysqli_query($conn, "select temp, humi, small, big, reading_time from SensorData");
$data = array(array('esp_data', '온도','습도', 'PM2.5', 'PM10'));
if($result){
    while($row=mysqli_fetch_array($result))
    {
        array_push($data, array($row['reading_time'], intval($row[0]), intval($row[1]), intval($row[2]), intval($row[3])));
    }
}
$options = array(
    'title' => '온도 (°C), 습도(%), PM2.5 (㎍/㎥), PM10 (㎍/㎥)',
    'width' => 1000, 'height' => 500
);
?>
<script src="//www.google.com/jsapi"></script>
<script>
    let data = <?= json_encode($data) ?>;
    let options = <?= json_encode($options) ?>;
    google.load('visualization', '1.0', {'packages':['corechart']});
    google.setOnLoadCallback(function() {
        let chart = new google.visualization.LineChart(document.querySelector('#chart_div'));
        chart.draw(google.visualization.arrayToDataTable(data), options);
    });
</script>
<div id="chart_div"></div>

