//컴퓨터학과 20170988 한소현
import java.util.ArrayList;
import java.util.Collections;

public class RandomList<T> {
	ArrayList<T> list;
	
	public RandomList() {
		list = new ArrayList<T>();
	}
	public void add(T item) {
		list.add(item);
	}
	public T select() throws ImproperArraySizeException{
		if (list == null || list.size() == 0) {
			throw new ImproperArraySizeException();
		}
		ArrayList<T> list2 = copyArray();
		Collections.shuffle(list2);
		return list2.get(0);
	}
	public void print() {
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i) + "\t");
		}
		System.out.println();
	}
	private ArrayList<T> copyArray() {
		ArrayList<T> list2 = new ArrayList<T>();
		for (int i = 0; i < list.size(); i++) {
			list2.add(i, list.get(i));
		}
		return list2;
	}
}
