//��ǻ���а� 20170988 �Ѽ���
public class Practice78E {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread t1 = new Thread(new Job("A"));
		Thread t2 = new Thread(new Job("B"));
		t1.start();
		t2.start();
	}

}
