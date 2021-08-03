import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * 
 */

/**
 * @author User501
 *
 */
public class GPIOPinTestMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//need to install wiringpi on dietpi first
    	LogWindow("             _ _ _ _ ||_mainApp_ _ _ _ _ _ _");
    	LogWindow("             \\  _  _ ||  _  _ _ ___");
    	LogWindow("             / /__/ \\|| |_/");
    	LogWindow("            / __   / || -  _ ___");
    	LogWindow("           / /  / /  ||/ /");
    	LogWindow("   _ _ _ _/ /  /  \\_/||  \\_ ______");
    	LogWindow(" ___________\\___\\____||______________");
    	LogWindow("");
    	LogWindow(" ***********************************");
    	LogWindow(" ***   GPIOPINTEST APPLICATION   ***");
    	LogWindow(" ***********************************");
    	LogWindow(" ***********************************");
    	LogWindow(" *** @author: C.A Torino         ***");
    	LogWindow(" *** @initial_date: 22 July 2021 ***");
    	LogWindow(" ***********************************");
    	LogWindow("");
    	
    	TestingA();
	}
	
	public static void TestingA()
    {
		LogWindow(" Press CTL-C to exit");
		try 
		{
			//Runtime r = Runtime.getRuntime();
			//r.exec(new String[] {"sudo", "gpio", "mode", "4", "out"});
			//r.exec(new String[] {"sudo", "gpio", "write", "4", "1"});
			//Thread.sleep(500);//500
			//r.exec(new String[] {"sudo", "gpio", "write", "4", "0"});
			Runtime r = Runtime.getRuntime();
			r.exec("gpio mode 4 out");
			while(true) 
			{
				r.exec("gpio write 4 1");
				Thread.sleep(500);
				r.exec("gpio write 4 0");
				Thread.sleep(500);
			}
			
		}
		catch(Exception e) 
		{
			LogWindow("Exception: " + e.getMessage());
		}
		
		LogWindow(" Testing Complete");
    }
	
	public static void LogWindow(String txt)
    {
		DateFormat dateFormat = new SimpleDateFormat("yyyy/dd/M HH:mm:ss");
		Date date = new Date();
        System.out.println("[" + dateFormat.format(date) + "] : " + txt);
    }
	
}
