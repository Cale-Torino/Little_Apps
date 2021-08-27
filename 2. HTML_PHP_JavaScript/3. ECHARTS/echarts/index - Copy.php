<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">

<title>ECharts</title>

<script src="dist/esl.js"></script>
<script src="dist/config.js"></script>
<script src="dist/jquery.min.js"></script>
<script src="dist/facePrint.js"></script>
<script src="dist/testHelper.js"></script>

<!-- including ECharts file -->
<script src="dist/echarts.js" class="chart"></script>

</head>
<body>
<style>
h1 {
    line-height: 60px;
    height: 60px;
    background: #146402;
    text-align: center;
    font-weight: bold;
    color: #eee;
    font-size: 14px;
}
.chart {
    height: 600px;
}
</style>

<h1>This is a Heading</h1>
<p>This is a paragraph.</p>

<!-- <div id="main" style="width: 100%;height:180px;"></div> -->

<div id="main" class="chart"></div>

<script>
$(document).ready(function(){
    console.log("IOT LOG: Login Form Ready!");
    //echart_pie();
});
//echart_pie();
require(
            (testHelper.hasURLParam('en')
                ? [
                    'echarts',
                    // 'echarts/lang/en',
                ]
                : [
                    'echarts'
                ]
            ).concat(
                [
                    // 'echarts/chart/bar',
                    // 'echarts/chart/line',
                    // 'echarts/component/legend',
                    // 'echarts/component/graphic',
                    // 'echarts/component/grid',
                    // 'echarts/component/tooltip',
                    // 'echarts/component/brush',
                    // 'echarts/component/toolbox',
                    // 'echarts/component/title',
                    // 'zrender/vml/vml'
                     'echarts'
                ]
            ),
            function (echarts) {

var chart = echarts.init(document.getElementById('main'));

chart.setOption({
    aria: {
        show: true
    },
    title : {
        text: '某站点用户访问来源',
        subtext: '纯属虚构',
        x:'center'
    },
    tooltip : {
        trigger: 'item',
        formatter: "{a} <br/>{b} : {c} ({d}%)"
    },
    legend: {
        orient: 'vertical',
        left: 'left',
        data: ['直接访问','邮件营销','联盟广告','视频广告(value is null)','搜索引擎']
    },
    series : [
        {
            name: '访问来源',
            type: 'pie',
            radius : '55%',
            center: ['50%', '60%'],
            data:[
                {value:335, name:'直接访问'},
                {value:310, name:'邮件营销'},
                {value:234, name:'联盟广告'},
                {value:null, name:'视频广告(value is null)'},
                {value:1548, name:'搜索引擎'}
            ],
            itemStyle: {
                emphasis: {
                    shadowBlur: 10,
                    shadowOffsetX: 0,
                    shadowColor: 'rgba(0, 0, 0, 0.5)'
                }
            }
        }
    ]
});
window.onresize = chart.resize;
}
);
</script>
</body>
</html>