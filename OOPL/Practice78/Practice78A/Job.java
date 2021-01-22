//컴퓨터학과 20170988 한소현
public class Job implements Runnable {
	public void run() {
		int n = 0;
		while(true) {
			System.out.println(n++ + "\t");
		}
	}
}
