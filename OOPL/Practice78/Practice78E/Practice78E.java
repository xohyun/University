//컴퓨터학과 20170988 한소현
public class Practice78E {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t1 = new Thread(new Job("A"));
		Thread t2 = new Thread(new Job("B"));
		t1.start();
		t2.start();
	}

}
