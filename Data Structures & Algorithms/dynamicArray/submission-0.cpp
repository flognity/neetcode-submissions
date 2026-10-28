class DynamicArray {
public:

    DynamicArray(int capacity) : m_size(0), m_capacity(capacity) {
        if (capacity > 0)
            m_arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] m_arr;
    }

    int get(int i) {
        if(i < m_size)
            return m_arr[i];
        return 0;
    }

    void set(int i, int n) {
        while (i > m_capacity)
            resize();
        m_arr[i] = n;
    }

    void pushback(int n) {
        if(m_size >= m_capacity)
            resize();
        m_arr[m_size] = n;
        m_size++;
    }

    int popback() {
        m_size--;
        return m_arr[m_size];
    }

    void resize() {
        m_capacity *= 2;
        int *newArr = new int[m_capacity];
        for(int i = 0; i < m_size; i++)
            newArr[i] = m_arr[i];
        delete[] m_arr;
        m_arr = newArr;
    }

    int getSize() {
        return m_size;
    }

    int getCapacity() {
        return m_capacity;
    }
private:
    int *m_arr;
    int m_size;
    int m_capacity;
};
