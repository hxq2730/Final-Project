//#include "SHA256.h"
//#include "AES.h"
//
//
//// Hàm mã hóa shift cipher để mã hóa mật khẩu để có thể chạy được chương trình
//string shiftCipherEncrypt(string password, int k)
//{
//	for (int i = 0; i < password.length(); i++)
//	{
//		if (isalnum(password[i]))
//		{
//			char base;
//			int max;
//			if (isupper(password[i]))
//			{
//				base = 'A';
//				max = 26;
//			}
//			else if (islower(password[i]))
//			{
//				base = 'a';
//				max = 26;
//			}
//			else
//			{
//				base = '0';
//				max = 10;
//			}
//			password[i] = (password[i] - base + k) % max + base;
//		}
//	}
//	return password;
//}
//
//// Hàm kiểm tra mật khẩu người dùng nhập vào có đúng hay không
//bool checkPassword()
//{
//	string input;
//	string encryptedPassword;
//	int count = 0;
//	int countErrTime = 0;
//	int waitTimeSecond = 0;
//	do
//	{
//		cout << "Vui long nhap mat khau de chay chuong trinh: "; // vd: 1234abcd
//		cin >> input;
//		//Ham lay thoi gian hien tai
//		time_t now = time(0);
//		tm* ltm = localtime(&now);
//
//		//Mat khau dong chinh la chuoi gio + phut hien tai + "salt" duoc them vao giua gio va phut:
//		//Luu y: 
//		string salt = "hxq";
//		string password = to_string(ltm->tm_hour) + salt + to_string(ltm->tm_min);
//
//		// De tang tinh bao mat, ta ma hoa mat khau nay bang shiftcipher voi k = 3;
//		encryptedPassword = shiftCipherEncrypt(password, 3);
//
//		// Neu chuoi nhap vao giong voi mat khau da duoc ma hoa thi tiep tuc chuong trinh 
//		if (input == encryptedPassword)
//		{
//			return true;
//		}
//		else
//		{
//			count++;
//			if (count == 5)
//			{
//				waitTimeSecond = 30 * (countErrTime + 1);
//				cout << "\nBan da nhap sai mat khau " << count * (countErrTime + 1) << " lan!. Vui long thu lai sau " << waitTimeSecond << " giay! " << endl;
//
//				while (waitTimeSecond > 0)
//				{
//					cout << "Con lai " << waitTimeSecond << " giay.\r" << flush;
//					// Đợi 1 giây
//					this_thread::sleep_for(std::chrono::seconds(1));
//					// Giảm giá trị thời gian đợi
//					waitTimeSecond--;
//					if (waitTimeSecond < 10)
//					{
//						cout << " ";  // Thêm dấu cách nếu số giây là một chữ số
//					}
//
//				}
//				count = 0;
//				countErrTime++;
//			}
//			system("cls");
//			cout << "Mat khau khong dung. Vui long nhap lai" << endl;
//		}
//	} while (input != encryptedPassword);
//}
//
//// Hàm kiểm tra key mã hóa(mật khẩu) người dùng nhập vào có mạnh hay không
//bool checkKeyPassword(string& key)
//{
//	bool checkDigit = false;
//	bool checkLetter = false;
//
//	for (char c : key)
//	{
//		if (isdigit(c))
//		{
//			checkDigit = true;
//		}
//		if (isalpha(c))
//		{
//			checkLetter = true;
//		}
//	}
//	return checkDigit && checkLetter;
//}
//
////Hàm nhập key mã hóa
//string inputKey()
//{
//	string password;
//	do
//	{
//		system("cls");
//		cout << "Nhap key (password) de ma hoa va giai ma: ";
//		cin >> password;
//		if (password.length() < 8)
//		{
//			cout << "Mat khau phai co it nhat 8 ky tu. Vui long nhap lai." << endl;
//			system("pause");
//		}
//		else
//		{
//			if (checkKeyPassword(password) == false)
//			{
//				cout << "Mat khau phai co it nhat 1 ky tu va 1 so. Vui long nhap lai." << endl;
//				system("pause");
//			}
//		}
//	} while (password.length() < 8 || checkKeyPassword(password) == false);
//	return password;
//}
//
//int main()
//{
//	/*if (checkPassword() == true)
//	{
//		system("cls");
//		cout << "Dang nhap thanh cong" << endl;
//		system("pause");
//	}
//	system("cls");*/
//
//	// Nhập key(mật khẩu) dùng cho mã hóa và giải mã AES
//	string password = inputKey();
//
//	// hash key mã hóa(password) nhập vào bằng MD5
//	string hashedPassword = sha256(password);
//	// In kết quả hash được mật khẩu ra màn hình
//	cout << "Mat khau da duoc hash thanh: " << hashedPassword << endl;
//
//	//Chuyển mật khẩu từ chuỗi(string) hexa về thành từng byte để mã hóa
//	unsigned char* key = hexStringToBytes(hashedPassword);
//
//	// Hàm mở rộng khóa
//	unsigned char* roundKeys;
//	roundKeys = keyExpansion(key);
//
//	// Khởi tạo hạt giống
//	srand(time(NULL));
//
//	//Khai báo biến
//	
//	unsigned char* salt = nullptr;
//	bool encrypted = false; // đánh dấu đã được mã hóa hay là chưa
//
//	string plain;
//	cout << "Nhap chuoi: ";
//	cin >> plain;
//
//	// tạo ngẫu nhiên IV và "salt"
//	salt = generateRandomSalt(16);
//	cout  << hex<< "salt: " << salt << endl;
//	
//	//Mã hóa tập tin
//	string cipherText;
//	cipherText = encrypt(plain, roundKeys, salt);
//
//	cout << "================================ Ma hoa ==================================" << endl;
//	cout << "Noi dung ma hoa la : ";
//
//	// In nội dung đã mã hóa ra màn hình dưới dạng hexa
//	for (unsigned char c : cipherText)
//	{
//		//cout << hex << (int)(unsigned char)c;
//		cout << hex << setw(2) << setfill('0') << (int)c;
//	}
//	cout << endl << endl;
//
//	//Giải mã nội dung tập tin
//	string plainText;
//	plainText = decrypt(cipherText, roundKeys, salt);
//
//	cout << "============================= Giai ma ==============================" << endl;
//	cout << "Noi dung sau khi giai ma duoc la: " << endl << plainText << endl << endl;
//
//	delete[] key;
//	delete[] salt;
//	delete[] roundKeys;
//	return 0;
//}
//
