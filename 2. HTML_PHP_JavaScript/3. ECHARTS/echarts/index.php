<!DOCTYPE html>
<html>
    <head>
    <meta charset="utf-8">

    <title>ECharts</title>

    <meta name="viewport" content="width=device-width, initial-scale=1" />

    <!-- JS LIBS -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <script src="dist/echarts.js"></script>
    <script src="dist/iq_blue_chalk.js"></script>

</head>
    <body>
        <style>
            html, body, .main {
                padding: 0;
                margin: 0;
                width: 100%;
                height: 300px;
                background: #333;
            }
            .label {

                padding: 10px;
                text-align: center;
            }
            .chart {background: #333; height: 350px; }
        </style>

<h1>This is a Heading</h1>
<p>This is a paragraph.</p>

<div class="main" id="main"></div>
<script>
$(document).ready(function(){
    console.log("IOT LOG: Login Form Ready!");
});

                var main = document.getElementById('main');

                var chart = echarts.init(main, 'iq_blue_chalk');

                var xAxisData = [];
                var data1 = [];
                var data2 = [];
                var data3 = [];
                var data4 = [];

                xAxisData.push('Test' + 1);
                data1.push('0.123');
                data2.push('0.523');
                data3.push('0.623');
                data4.push('0.343');

                for (var i = 0; i < 5; i++) {
                    xAxisData.push('Test' + i);
                    data1.push((Math.random() + 0.2).toFixed(3));
                    data2.push((Math.random() + 0.3).toFixed(3));
                    data3.push((Math.random() + 0.2).toFixed(3));
                    data4.push((Math.random() + 0.2).toFixed(3));
                }



                var itemStyle = {
                    normal: {
                        //borderColor: 'white',
                        // borderWidth: 3,
                        // shadowBlur: 10,
                        // shadowOffsetX: 0,
                        // shadowOffsetY: 5,
                        // shadowColor: 'rgba(0, 0, 0, 0.4)',
                        lineStyle: {
                            width: 2
                            // shadowBlur: 10,
                            // shadowOffsetX: 0,
                            // shadowOffsetY: 5,
                            // shadowColor: 'rgba(0, 0, 0, 0.4)'
                        },
                        areaStyle: {
                        }
                    }
                };

                chart.setOption({
                    legend: {data: ['line', 'line2', 'line3']
                    },
                    tooltip: {
                        trigger: 'axis',
                        axisPointer: {type: 'line'}
                    },
                    toolbox: {
                                 show : true,
                                 feature : {
                                     mark : {show: true},//title: 'Mark'
                                     dataView : {show: true, readOnly: false},
                                     magicType : {show: true, type: ['line', 'bar']},
                                     restore : {show: true},
                                     saveAsImage : {show: true}
                                 }
                             },
                    xAxis: {
                        // data: ['Test1', 'Test2', 'Test3', 'Test4', 'Test5',]
                        data: xAxisData,
                        boundaryGap: false,
                        // inverse: true,
                        splitArea: {
                            show: true
                        }
                    },
                    yAxis: {
                    },
                    series: [{
                        id: 'aaa',
                        name: 'line33333',
                        type: 'line',
                        stack: 'all',
                        symbolSize: 10,
                        data: data3,
                        itemStyle: itemStyle,
                        label: {
                            normal: {
                                show: true
                            }
                        },
                        connectNulls: true,
                        smooth: true
                    }]
                });

                // setTimeout(function () {
                //     chart.setOption({
                //         series: [
                //             {
                //                 id: 'aaa',
                //                 name: 'xxxxxxxxxxxxxxxx',
                //                 data: data4,
                //             }
                //         ]
                //     });
                // }, 1000);
                window.onresize = chart.resize;

</script>
</body>
</html>