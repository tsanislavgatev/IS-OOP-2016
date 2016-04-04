#pragma once


template <class T>
class Example
{
    public:
        Example();


    private:


    public:
        T sum(T,T);
        T mult(T,T);
        T diff(T,T);
        void sortInsertion(T*, int);
};

template <class T>
Example<T>::Example()
{

}

template <class  T>
T Example<T>::sum(T first, T second)
{
    return first + second;
}

template <class T>
T Example<T>::diff(T first, T second)
{
    if(first < second)
    {
        return second - first;
    }
    return first - second;
}

template <class T>
void Example<T>::sortInsertion(T* arrayOfElements, int sizeOfArray)
{
	for(int i = 0; i < sizeOfArray; i++)
    {
        int j;
		j = i;
		while (j > 0 && arrayOfElements[j] < arrayOfElements[j-1])
		{
            int temp = arrayOfElements[j];
            arrayOfElements[j] = arrayOfElements[j-1];
			arrayOfElements[j-1] = temp;
			j--;
        }
    }
}

template <class T>
T Example<T>::mult(T first, T second)
{
    return first * second;
}
