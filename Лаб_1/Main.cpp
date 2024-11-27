//Программно реализовать алгоритм шифрования  данных «Система шифрования Цезаря».
using namespace std;
#include <iostream>
#include <string>

string caesarCipher(string, int);
string caesarDecipher(string, int);
bool Check_string(string);

int main() {
	setlocale(LC_ALL, "Russian");
	string plaintext;
	int shift;

	cout << "Введите текст для шифрования: ";
	getline(cin, plaintext);

	while (!Check_string(plaintext)) {
		cin.clear();
		cout << "Неправильно! Повторите ввод!" << endl;
		getline(cin, plaintext);

	}
	cout << "Введите сдвиг: ";
	cin >> shift;

	string ciphertext = caesarCipher(plaintext, shift);
	cout << "Зашифрованный текст: " << ciphertext << endl;
	string decryptedText = caesarDecipher(ciphertext, shift);
	cout << "Расшифрованный текст: " << decryptedText << endl;
	return 0;
}

string caesarCipher(string text, int shift) {
	string result = "";      //зашифрованный текст 
	for (char& c : text) {   //работаем с каждым символом по ссылке, чтобы иметь возможность изменять его значение.
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';  //Определение базового символа
			c = base + (c - base + shift) % 26;
		}
		result += c;
	}
	return result;
}

string caesarDecipher(string text, int shift) {
	string result = "";
	for (char& c : text) {
		if (isalpha(c)) {
			char base = islower(c) ? 'a' : 'A';
			c = base + (c - base - shift + 26) % 26; // Вычитаем сдвиг и добавляем 26 для корректной обработки отрицательных значений
		}
		result += c;
	}
	return result;
}

bool Check_string(string text) {          //выполняем проверку, что пользователь ввел строку из текста(пробелы учитываем) через посимвольное сравнение 
	int flag = 0;
	for (int i = 0; i < text.size(); i++)
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') || (text[i] == ' ')) {
			flag++;
			if (flag == i) return true;
		}
		else return false;
}