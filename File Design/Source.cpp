//#include "AES.h"
//#include "SHA256.h"
//#include <sstream>
//#include <ctime>
//#include <bitset>
//struct Date
//{
//    int month;
//    int day;    
//    int year;
//};
//
//struct Time
//{
//    int hour;
//    int minute;
//    int second;
//};
//
//struct Header
//{
//    Date createDate;
//    Time createTime;
//    Date updateDate;
//    Time updateTime;
//    string encryptionKey;
//    unsigned char* iv;
//    int partSize;
//    int numTeachers;
//    int numBackupTeachers;
//    int numStudents;
//};
//
//struct Teacher
//{
//    int ordinalNumber;
//    string status;
//    string teacherID;
//    string fullName;
//    Date birthDate;
//    Date joinDate;
//    string encryptedPhone;
//    string encryptedCCCD;
//};
//
//struct Student
//{
//    int ordinalNumber;
//    string status;
//    string studentID;
//    string fullName;
//    string birthDate;
//    string joinDate;
//    string encryptedPhone;
//    string encryptedCCCD;
//};
//
//unsigned char* convertStringToUnsignedChar(const string& str)
//{
//    unsigned char* result = new unsigned char[str.length() + 1];
//    memcpy(result, str.c_str(), str.length());
//    result[str.length()] = '\0';
//    return result;
//}
//
//Date readDate(const string& dateString) 
//{
//    Date date;
//    sscanf(dateString.c_str(), "%d/%d/%d", &date.month, &date.day, &date.year);
//    return date;
//}
//
//// Helper function to read Time from buffer
//Time readTime(const string& timeString)
//{
//    Time time;
//    sscanf(timeString.c_str(), "%d:%d:%d", &time.hour, &time.minute, &time.second);
//    return time;
//}
//
////void readHeader(ifstream& inputFile, Header& header) 
////{
////    char buffer[118];
////    inputFile.getline(buffer, sizeof(buffer));
////    header.createDate = readDate(string(buffer, 10));
////    header.createTime = readTime(string(buffer + 11, 8));
////    header.updateDate = readDate(string(buffer + 20, 10));
////    header.updateTime = readTime(string(buffer + 31, 8));
////    header.encryptionKey = string(buffer + 40, 64);
////
////    // Read integers until comma is encountered
////    istringstream bufferStream(buffer + 105);
////
////    // Function to read an integer from the buffer stream
////    auto readInt = [&bufferStream]() {
////        string str;
////        getline(bufferStream, str, ',');
////        return stoi(str);
////        };
////
////    // Read integers
////    header.partSize = readInt();
////    header.numTeachers = readInt();
////    header.numBackupTeachers = readInt();
////    header.numStudents = readInt();
////}
//
////void readHeader(ifstream& inputFile, Header& header) 
////{
////    char buffer[128]; 
////    inputFile.read(buffer, sizeof(buffer) - 1);
////    buffer[sizeof(buffer) - 1] = '\0';
////
////    header.createDate = readDate(string(buffer, 10));
////    header.createTime = readTime(string(buffer + 11, 8));
////    header.updateDate = readDate(string(buffer + 20, 10));
////    header.updateTime = readTime(string(buffer + 31, 8));
////    header.encryptionKey = string(buffer + 40, 64);
////
////    // Read integers until comma is encountered
////    istringstream bufferStream(buffer + 105);
////
////    // Function to read an integer from the buffer stream
////    auto readInt = [&bufferStream]() {
////        string str;
////        getline(bufferStream, str, ',');
////        return stoi(str);
////        };
////
////    // Read integers
////    header.partSize = readInt();
////    header.numTeachers = readInt();
////    header.numBackupTeachers = readInt();
////    header.numStudents = readInt();
////}
//
//void readHeader(fstream& inputFile, Header& header) {
//    char buffer[256]; // Đảm bảo đủ kích thước cho dữ liệu đầu vào
//    inputFile.getline(buffer, sizeof(buffer));
//
//    // Extracting values from the buffer using substrings
//    string bufferStr(buffer);
//
//    // Sử dụng hàm substr để trích xuất các giá trị
//    header.createDate = readDate(bufferStr.substr(0, 10));
//    header.createTime = readTime(bufferStr.substr(11, 8));
//    header.updateDate = readDate(bufferStr.substr(20, 10));
//    header.updateTime = readTime(bufferStr.substr(31, 8));
//    header.encryptionKey = bufferStr.substr(40, 64);
//    header.iv = convertStringToUnsignedChar(bufferStr.substr(105, 16));
//    // Read integers until comma is encountered
//    istringstream bufferStream(bufferStr.substr(122));
//
//    // Function to read an integer from the buffer stream
//    auto readInt = [&bufferStream]() 
//    {
//        string str;
//        getline(bufferStream, str, ',');
//        return stoi(str, nullptr, 2); // Chuyển đổi từ chuỗi nhị phân sang số nguyên
//    };
//
//    // Read integers
//    header.partSize = readInt();
//    header.numTeachers = readInt();
//    header.numBackupTeachers = readInt();
//    header.numStudents = readInt();
//}
//
////void readTeachers(ifstream& inputFile, int numTeachers, vector<Teacher>& teachers)
////{
////    teachers.resize(numTeachers);
////    for (int i = 0; i < numTeachers; ++i)
////    {
////        inputFile >> teachers[i].ordinalNumber >> teachers[i].status >> teachers[i].teacherID;
////        inputFile.ignore(); // Ignore newline character
////        getline(inputFile, teachers[i].fullName);
////        inputFile >> teachers[i].birthDate >> teachers[i].joinDate;
////        inputFile.ignore(); // Ignore newline character
////        getline(inputFile, teachers[i].encryptedPhone);
////        getline(inputFile, teachers[i].encryptedCCCD);
////    }
////}
//
//void readStudents(ifstream& inputFile, int numStudents, vector<Student>& students)
//{
//    students.resize(numStudents);
//    for (int i = 0; i < numStudents; ++i)
//    {
//        inputFile >> students[i].ordinalNumber >> students[i].status >> students[i].studentID;
//        inputFile.ignore(); // Ignore newline character
//        getline(inputFile, students[i].fullName);
//        inputFile >> students[i].birthDate >> students[i].joinDate;
//        inputFile.ignore(); // Ignore newline character
//        getline(inputFile, students[i].encryptedPhone);
//        getline(inputFile, students[i].encryptedCCCD);
//    }
//}
//
//void writeDate(fstream& outputFile, const Date& date)
//{
//    outputFile << setfill('0') << setw(2) << date.month << "/" << setw(2) << date.day << "/" << date.year;
//}
//
//// Helper function to write Time to output stream
//void writeTime(fstream& outputFile, const Time& time) 
//{
//    outputFile << setfill('0') << setw(2) << time.hour << ":" << setw(2) << time.minute << ":" << setw(2) << time.second;
//}
//
//string intToBinaryString(int number)
//{
//    return bitset<sizeof(int) * 8>(number).to_string();
//}
//
//void writeHeader(fstream& outputFile, const Header& header) 
//{
//    writeDate(outputFile, header.createDate);
//    outputFile << ",";
//    writeTime(outputFile, header.createTime);
//    outputFile << ",";
//    writeDate(outputFile, header.updateDate);
//    outputFile << ",";
//    writeTime(outputFile, header.updateTime);
//    outputFile << ",";    
//    outputFile << header.encryptionKey << "," << header.iv <<",";
//    
//    outputFile << intToBinaryString(header.partSize);
//    outputFile << ",";
//    outputFile << intToBinaryString(header.numTeachers);
//    outputFile << ",";
//    outputFile << intToBinaryString(header.numBackupTeachers);
//    outputFile << ",";
//    outputFile << intToBinaryString(header.numStudents);
//    outputFile << "\n";
//}
//
////void writeHeader(ofstream& outputFile, const Header& header)
////{
////    writeDate(outputFile, header.createDate);
////    outputFile << ",";
////    writeTime(outputFile, header.createTime);
////    outputFile << ",";
////    writeDate(outputFile, header.updateDate);
////    outputFile << ",";
////    writeTime(outputFile, header.updateTime);
////    outputFile << ",";
////
////    outputFile << header.encryptionKey << ",";
////    outputFile << header.partSize << "," << header.numTeachers << "," << header.numBackupTeachers << "," << header.numStudents << "\n";  
////}
//
//void writeTeacher(fstream& outputFile, const Teacher& teacher)
//{
//    outputFile << teacher.ordinalNumber << "," << teacher.status << "," << teacher.teacherID << ","
//        << teacher.fullName << ",";
//    writeDate(outputFile, teacher.birthDate);
//    outputFile << ",";
//    writeDate(outputFile, teacher.joinDate);
//    outputFile << ","; 
//    outputFile << teacher.encryptedPhone << "," << teacher.encryptedCCCD << "\n";
//}
//
//void writeStudent(ofstream& outputFile, const Student& student)
//{
//    outputFile << student.ordinalNumber << ", " << student.status << ", " << student.studentID << ", "
//        << student.fullName << ", " << student.birthDate << ", " << student.joinDate << ", "
//        << student.encryptedPhone << ", " << student.encryptedCCCD << "\n";
//}
//
//void getCurrentDateTime(Date& currentDate, Time& currentTime)
//{
//    // Lấy thời gian hệ thống
//    time_t now = time(nullptr);
//
//    // Chuyển đổi thời gian thành cấu trúc tm để có thể lấy ngày và giờ
//    tm* localTime = localtime(&now);
//
//    // Gán giá trị cho struct Date
//    currentDate.day = localTime->tm_mday;
//    currentDate.month = localTime->tm_mon + 1;  // tm_mon bắt đầu từ 0
//    currentDate.year = localTime->tm_year + 1900;  // tm_year là số năm kể từ 1900
//
//    // Gán giá trị cho struct Time
//    currentTime.hour = localTime->tm_hour;
//    currentTime.minute = localTime->tm_min;
//    currentTime.second = localTime->tm_sec;
//}
//
//
//void printDate(const Date& date)
//{
//    cout << setfill('0') << setw(2) << date.month << "/" << setw(2) << date.day << "/" << date.year;
//}
//
//void printTime(const Time& time)
//{
//    cout << setfill('0') << setw(2) << time.hour << ":" << setw(2) << time.minute << ":" << setw(2) << time.second;
//}
//
//void printHeader(const Header& header) 
//{
//    cout << "Create Date: ";
//    printDate(header.createDate);
//    cout << "\nCreate Time: ";
//    printTime(header.createTime);
//    cout << "\nUpdate Date: ";
//    printDate(header.updateDate);
//    cout << "\nUpdate Time: ";
//    printTime(header.updateTime);
//    cout << "\nEncryption Key: " << header.encryptionKey << "\n";
//    cout << "IV: " << header.iv << endl;
//    cout << "Part Size: " << header.partSize << "\n";
//    cout << "Number of Teachers: " << header.numTeachers << "\n";
//    cout << "Number of Backup Teachers: " << header.numBackupTeachers << "\n";
//    cout << "Number of Students: " << header.numStudents << "\n";
//}
//
//void printTeachers(const vector<Teacher>& teachers) {
//    for (const Teacher& teacher : teachers) {
//        cout << "Ordinal Number: " << teacher.ordinalNumber << "\n";
//        cout << "Status: " << teacher.status << "\n";
//        cout << "Teacher ID: " << teacher.teacherID << "\n";
//        cout << "Full Name: " << teacher.fullName << "\n";
//        //cout << "Birth Date: " << teacher.birthDate << "\n";
//        printDate(teacher.birthDate);
//        cout << "\n";
//        //cout << "Join Date: " << teacher.joinDate << "\n";
//        printDate(teacher.joinDate);
//        cout << "\n";
//        cout << "Encrypted Phone: " << teacher.encryptedPhone << "\n";
//        cout << "Encrypted CCCD: " << teacher.encryptedCCCD << "\n";
//        cout << "----------------\n"; // Separator between teachers
//    }
//}
//
//void printStudents(const vector<Student>& students) {
//    for (const Student& student : students) {
//        cout << "Ordinal Number: " << student.ordinalNumber << "\n";
//        cout << "Status: " << student.status << "\n";
//        cout << "Student ID: " << student.studentID << "\n";
//        cout << "Full Name: " << student.fullName << "\n";
//        cout << "Birth Date: " << student.birthDate << "\n";
//        cout << "Join Date: " << student.joinDate << "\n";
//        cout << "Encrypted Phone: " << student.encryptedPhone << "\n";
//        cout << "Encrypted CCCD: " << student.encryptedCCCD << "\n";
//        cout << "----------------\n"; // Separator between students
//    }
//}
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
//
//
//// Bảng quán lý teacher
//void writeTeachersStatus(ofstream& outputFile, const vector<Teacher>& teachers)
//{
//    outputFile << "\n";
//
//    // Ghi trạng thái của toàn bộ giáo viên
//    for (const Teacher& teacher : teachers)
//    {
//        outputFile << teacher.status;
//    }
//    outputFile << "\n";
//}
//
//void addTeacher(vector<Teacher>& teachers, const Teacher& newTeacher, Header& header)
//{
//    // Thêm giáo viên mới vào cuối danh sách
//    teachers.push_back(newTeacher);
//
//    // Cập nhật trạng thái trong bảng quản lý giáo viên
//    header.numTeachers++; // Tăng số lượng giáo viên
//}
//
//void addTeacherAndUpdateStatus(fstream& outputFile, vector<Teacher>& teachers, Header& header, string status, const Teacher& newTeacher)
//{
//    // Thêm giáo viên mới vào danh sách
//    teachers.push_back(newTeacher);
//    //header.numTeachers++;
//
//    // Cập nhật trạng thái
//    teachers.back().status = status;
//    writeTeacher(outputFile, newTeacher);
//}
//
//void updateTeacherStatus(vector<Teacher>& teachers, Header& header, int teacherIndex, char newStatus)
//{
//    // Kiểm tra xem index có hợp lệ không
//    if (teacherIndex >= 0 && teacherIndex < header.numTeachers)
//    {
//        // Cập nhật trạng thái của giáo viên tại index
//        teachers[teacherIndex].status = newStatus;
//    }
//}
//
//void updateNumTeachersInHeader(fstream& file, int newNumTeachers)
//{
//   /* fstream file(filename, ios::in | ios::out);
//    if (!file.is_open()) {
//        cerr << "Error opening file: " << filename << endl;
//        return;
//    }*/
//
//    // Đọc Header từ file
//    Header header;
//    readHeader(file, header);
//
//    // Cập nhật số lượng giáo viên
//    header.numTeachers = newNumTeachers;
//
//    // Di chuyển vị trí con trỏ về đầu file
//    file.seekg(0, ios::beg);
//
//    // Ghi lại Header đã được cập nhật vào file
//    writeHeader(file, header);
//
//    // Đóng file
//    file.close();
//}
//
//void addTeacherAndUpdateHeader(fstream& outputFile, vector<Teacher>& teachers, Header& header, string status, const Teacher& newTeacher)
//{
//    // Thêm giáo viên mới vào danh sách và cập nhật trạng thái
//    addTeacherAndUpdateStatus(outputFile, teachers, header, status, newTeacher);
//
//    // Cập nhật số lượng giáo viên trong Header và ghi lại vào file
//    updateNumTeachersInHeader(outputFile, teachers.size());
//}
//
//Teacher initNewTeacher(Header& header, string status, int id, string teacherID,  string fullName, Date birthDate, Date joinDate, string phoneNumber, string cccd)
//{
//    Teacher newTeacher;
//    unsigned char* roundKeys;
//    roundKeys = keyExpansion(hexStringToBytes(header.encryptionKey));
//    string encryptedPhone = encrypt(phoneNumber, roundKeys, header.iv);
//    string encryptedCCCD = encrypt(cccd, roundKeys, header.iv);
//    return { id, status, fullName, teacherID, birthDate, joinDate, encryptedPhone, encryptedCCCD };
//}
//
//void writeTeachers(fstream& outputFile, const vector<Teacher>& teachers)
//{
//    for (const Teacher& teacher : teachers) 
//    {
//        writeTeacher(outputFile, teacher);
//    }
//}
//
//int main() 
//{
//    fstream outputFile("filedesign.txt");
//
//    if (!outputFile.is_open()) {
//        cerr << "Error opening input.txt for writing\n";
//        return 1;
//    }
//
//    //Ghi header
//    Header header;
//    Date currentDate;
//    Time currentTime;
//    getCurrentDateTime(currentDate, currentTime);
//    header.createDate = currentDate;
//    header.createTime = currentTime;
//    header.updateDate = header.createDate;
//    header.updateTime = header.createTime;
//
//    string inputKey = "abcd1234";
//    string key = sha256(inputKey);
//    header.encryptionKey = key;
//
//    srand(time(NULL));
//    unsigned char* iv = generateRandomSalt(16);
//    header.iv = iv;
//    int elementSize = 118;
//    
//    header.partSize = elementSize;
//
//    int numberTeacher = 3;
//    header.numTeachers = numberTeacher;
//
//    int numberBackupTeacher = 10;
//    header.numBackupTeachers = numberBackupTeacher;
//
//    int numberStudent = 10;
//    header.numStudents = numberStudent;
//    
//    writeHeader(outputFile, header);
//
//    //Ghi backup header
//    Header backupHeader;
//    backupHeader.createDate = currentDate;
//    backupHeader.createTime = currentTime;
//    backupHeader.updateDate = backupHeader.createDate;
//    backupHeader.updateTime = backupHeader.createTime;
//    backupHeader.encryptionKey = key;
//    backupHeader.iv = iv;
//    backupHeader.partSize = elementSize;
//    backupHeader.numTeachers = numberTeacher;
//    backupHeader.numBackupTeachers = numberBackupTeacher;
//    backupHeader.numStudents = numberStudent;
//
//    writeHeader(outputFile, backupHeader);
//    
//    //Ghi bảng quản lý trạng thái của giáo viên
//    vector<string> teacherStatus;    
//    for (int i = 0; i < header.numTeachers - 1; ++i)
//    {
//        teacherStatus.push_back("11");
//        outputFile << "11" <<",";
//    }
//    outputFile << "11" << "\n";
//       
//    Teacher teacher1 = initNewTeacher(header, "11", 1, "GV001", "Nguyen Van A", { 01,13,2000 }, { 01,14,2000 }, "0123456789", "123456789111");
//    Teacher teacher2 = initNewTeacher(header, "11", 2, "GV002", "Nguyen Van B", { 01,13,2000 }, { 01,14,2000 }, "3452345602", "237653475235");
//    Teacher teacher3 = initNewTeacher(header, "11", 3, "GV003", "Nguyen Van C", { 01,13,2000 }, { 01,14,2000 }, "7523457345", "762394753495");
//
//    vector<Teacher> teachers;
//    teachers.push_back(teacher1);
//    teachers.push_back(teacher2);
//    teachers.push_back(teacher3);
//    writeTeachers(outputFile, teachers);
//
// 
//    // Close the file
//    outputFile.close();
//    cout << "Data written to input.txt\n";
//
//   // ifstream inputFile("filedesign.txt");
//   // if (!inputFile.is_open()) 
//   // {
//   //     cerr << "Error opening input.txt\n";
//   //     return 1;
//   // }
//
//   // vector<Teacher> backupTeachers;
//   // Header header, backupHeader;
//   // vector<Teacher> teachers;
//   // vector<Student> students;
//
//   // readHeader(inputFile, header);
//   // readHeader(inputFile, backupHeader);
//   ///* readTeachers(inputFile, header.numTeachers, teachers);
//   // readTeachers(inputFile, header.numBackupTeachers, teachers);
//   // readStudents(inputFile, header.numStudents, students);*/
//
//   // // Do something with the data, e.g., print it
//   // cout << "\n============================ Header ===============================" << endl << endl;
//   // printHeader(header);
//
//   // cout << "\n============================ Backup Header ===============================" << endl << endl;
//   // printHeader(backupHeader);
//
//   ///* cout << "\n============================ Teacher ===============================" << endl << endl;
//   // printTeachers(teachers);
//
//   // cout << "\n============================ Backup teacher ===============================" << endl << endl;
//   // printTeachers(backupTeachers);
//
//   // cout << "\n============================ Students ===============================" << endl << endl;
//   // printStudents(students);*/
//    
//    return 0;
//}