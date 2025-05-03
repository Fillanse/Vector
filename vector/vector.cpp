#include <iostream>


using namespace std;

template <typename T>
class Vector {

private:
	void check_capacity() {
		if (size_ == capacity_) {
			int* temp = new int[capacity_ * 2];
			for (int i = 0; i < size_; i++) {
				temp[i] = arr_[i];
			}
			delete[] arr_;
			arr_ = temp;
			capacity_ *= 2;
		}
	}

	int size_;
	int capacity_; 
	T* arr_; 

public:

	Vector(int size) : arr_(new T[size]), size_(size) {}
	
	Vector() : Vector(10) {}

	Vector(const Vector& other) : arr_(new T[other.size_]{}), size_(other.size_) {
		for (int i = 0; i < size_; i++) {
			arr_[i] = other.arr_[i];
		};
	}

	Vector(Vector&& other) : size_(other.size_), capacity_(other.capacity_), arr_(other.arr_) {
		other.arr_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}

	Vector(const initializer_list<T> list) : Vector(list.size()) {
		int i = 0;
		for (const int& element : list) {
			arr_[i] = element;
			i++;
		}
	}

	Vector& operator=(const Vector& other) {
		if (!(this == &other)) {
			delete[] arr_;
			arr_ = new T[other.size_];
			size_ = other.size_;
			for (int i = 0; i < size_; i++) {
				arr_[i] = other.arr_[i];
			}
		}
		return *this;
	}

	Vector& operator=(Vector&& other) {
		if (!(this == &other)) {
			delete[] arr_;
			arr_ = other.arr_;
			size_ = other.size_;
			other.arr_ = nullptr;
			other.size_ = 0;
		}
		return *this;
	}

	T& operator[](int index) {
		if (index >= 0 && index < size_) {
			return arr_[index];
		}
	}

	T operator[](int index) const {
		if (index >= 0 && index < size_) {
			return arr_[index];
		}
	}

	void push_back(const int value) {
		check_capacity();
		arr_[size_] = value;
		size_++;
	}

	void pop_back() {
		if (size_ > 0) {
			size_--;
		}
	}

	void insert(const int index, const int value) {
		if (index < 0 || index > size_) {
			cout << "Invalid index" << endl;
			return;
		}
		check_capacity();
		for (int i = size_; i > index; i--) {
			arr_[i] = arr_[i - 1];
		}
		arr_[index] = value;
		size_++;
	}

	void erase(const int index) {
		if (index < 0 || index >= size_) {
			cout << "Invalid index" << endl;
			return;
		}
		for (int i = index; i < size_ - 1; i++) {
			arr_[i] = arr_[i + 1];
		}
		size_--;
	}

	void set_value(const int index, const int value) {
		if (index < 0 || index >= size_) {
			cout << "Invalid index" << endl;
			return;
		}
		arr_[index] = value;
	}

	int get_value(const int index) {
		if (index < 0 || index >= size_) {
			cout << "Invalid index" << endl;
			return;
		}
		arr_[index];
	}

	int size() {
		return size_;
	}

	int capacity() {
		return capacity_;
	}

	void print() {
		for (int i = 0; i < size_; i++) {
			cout << arr_[i] << " ";
		}
		cout << endl;
	}

	~Vector() {
		delete[] arr_;
	}
};

int main() {
	Vector<int> v1(2);
	v1.print;
}
