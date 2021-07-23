<!doctype html>
<html lang="en">

<head>
  <title>Login | API Doc</title>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0" name="viewport" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
  <!--     Fonts and icons     -->
  <link rel="stylesheet" type="text/css" href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700|Roboto+Slab:400,700|Material+Icons" />
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/latest/css/font-awesome.min.css">
  <!-- Material Kit CSS -->
  <link href="assets/css/material-dashboard.css?v=2.1.0" rel="stylesheet" />
  <link href="assets/css/mdcss.css" rel="stylesheet" />
</head>

<body class="dark-edition">
  <div class="wrapper ">
    <div class="sidebar" data-color="azure" data-background-color="black" data-image="./assets/img/sidebar-2.jpg">
      <!--
      Tip 1: You can change the color of the sidebar using: data-color="purple | azure | green | orange | danger"

      Tip 2: you can also add an image using data-image tag
  -->
      <div class="logo">
        <a href="./index.php" class="simple-text logo-normal">
          API Doc
        </a>
      </div>
      <div class="sidebar-wrapper">
        <ul class="nav">
          <li class="nav-item active">
            <a class="nav-link" href="./login.php">
              <p>Login</p>
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="./logout.php">
              <p>Logout</p>
            </a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="./getServerStatus.php">
              <p>Get Server Status</p>
            </a>
          </li>
          <!-- your sidebar here -->
        </ul>
      </div>
    </div>
    <div class="main-panel">
      <!-- Navbar -->
      <nav class="navbar navbar-expand-lg navbar-transparent navbar-absolute fixed-top ">
        <div class="container-fluid">
          <div class="navbar-wrapper">
            <a class="navbar-brand" href="javascript:void(0)">Login</a>
          </div>
          <button class="navbar-toggler" type="button" data-toggle="collapse" aria-controls="navigation-index" aria-expanded="false" aria-label="Toggle navigation">
            <span class="sr-only">Toggle navigation</span>
            <span class="navbar-toggler-icon icon-bar"></span>
            <span class="navbar-toggler-icon icon-bar"></span>
            <span class="navbar-toggler-icon icon-bar"></span>
          </button>
          <div class="collapse navbar-collapse justify-content-end">
            <ul class="navbar-nav">
              <!-- <li class="nav-item">
                <a class="nav-link" href="javascript:void(0)">
                  <i class="material-icons">notifications</i>
                  <p class="d-lg-none d-md-block">
                    Notifications
                  </p>
                </a>
              </li> -->
              <!-- your navbar here -->
            </ul>
          </div>
        </div>
      </nav>
      <!-- End Navbar -->
      <div class="content">
        <div class="container-fluid">
        <!-- your content here -->
        <!-- <iframe id="markdownF" src="Templatemd.md" title="MarkDown" width="100%" height="300" style="border:1px solid black;"></iframe> -->
        <div id="markdownF"></div>
          <!-- your content here -->
        </div>
      </div>
      <footer class="footer">
        <div class="container-fluid">
          <nav class="float-left">
            <ul>
              <li>
                <a href="https://www.techrad.co.za">
                TechRad
                </a>
              </li>
            </ul>
          </nav>
          <div class="copyright float-right">
            &copy;
            <script>
              document.write(new Date().getFullYear())
            </script>, made with <i class="material-icons">favorite</i> by
            <a href="https://www.techrad.co.za" target="_blank">C.A Torino</a>.
          </div>
          <!-- your footer here -->
        </div>
      </footer>
    </div>
  </div>
  <!--   Core JS Files   -->
  <script src="./assets/js/core/jquery.min.js"></script>
  <script src="./assets/js/core/popper.min.js"></script>
  <script src="./assets/js/core/bootstrap-material-design.min.js"></script>
  <script src="https://unpkg.com/default-passive-events"></script>
  <!-- <script src="./assets/js/plugins/perfect-scrollbar.jquery.min.js"></script> -->
  <!-- Place this tag in your head or just before your close body tag. -->
  <script async defer src="https://buttons.github.io/buttons.js"></script>
  <!-- Chartist JS -->
  <script src="./assets/js/plugins/chartist.min.js"></script>
  <!--  Notifications Plugin    -->
  <script src="./assets/js/plugins/bootstrap-notify.js"></script>
  <!-- Control Center for Material Dashboard: parallax effects, scripts for the example pages etc -->
  <script src="./assets/js/material-dashboard.js?v=2.1.0"></script>
<!--  For MarkDown    -->
  <!-- <script src="https://cdnjs.cloudflare.com/ajax/libs/markdown-it/12.0.6/markdown-it.min.js"></script> -->
  <script src="./assets/js/markdown-it/dist/markdown-it.min.js"></script>

  <script>
    $(document).ready(function() {
      $().ready(function() {

async function loadFileAndPrintToConsole(url) {
  try {
    const response = await fetch(url);
    const data = await response.text();
    //https://markdown-it.github.io/markdown-it/
    //var md = window.markdownit();
    var md = window.markdownit({
      html: true,
      linkify: true,
      typographer: true
    });
    var result = md.render(data);
    document.getElementById("markdownF").innerHTML = result;
    //console.log(data);
  } catch (err) {
    console.error(err);
  }
}
var text = loadFileAndPrintToConsole('md_files/login.md');
      });
    });
  </script>
</body>

</html>