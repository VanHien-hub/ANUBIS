#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct LapTop
{
	char maSP[40] = {""};
	char maCPU[30];
	char RAM[15];
	char LoaiDia[10];
	char DungLuongDia[10];
    float gia;
};


string Menu_Chinh[] =
{
	"  Chương Trình Quản Lý Laptop",
	"  1.In danh mục Laptop",
	"  2.Thêm 1 Laptop vào danh sách",
	"  3.Xóa Laptop theo mã sản phẩm",
	"  4.Chỉnh sửa thông tin laptop",
	"  5.Tìm kiếm theo mã sản phẩm",
	"  6.Tìm kiếm theo khoảng giá",
	"  7.Sắp xếp theo giá",
	"  8.Thống kê Laptop", // bao nhiêu cpu intel,amd, ram 16gb trở lên, ssd 512gb trở lên
	"  9.Ghi File",
	"  10.Kết thúc chương trình",
	"  Mời chọn các chức năng trên (1...10): "
};

string Menu_TimKiem[] =
{
	"Thuật Toán Tìm Kiếm",
	"1.Linear Search",
	"2.Binary Search",
	"3.Quay về"
};

string Menu_SapXep[] =
{
	"Thuật Toán Sắp Xếp",
	"1.Bubble Sort",
	"2.Shaker Sort",
	"3.Selection Sort",
	"4.Insertion Sort",
	"5.InterChange Sort",
	"6.Quay lại Menu"
};

string Menu_ChinhSua[] =
{
    "Bạn muốn chỉnh sửa thông tin nào của Laptop ?",
    "1.Mã sản phẩm",
    "2.Mã CPU" ,
    "3.RAM",
    "4.Loại ổ đĩa", 
    "5.Dung lượng đĩa", 
    "6.Giá bán", 
    "7.Chỉnh sửa tất cả", 
    "8.Thoát chỉnh sửa",
    "Mời chọn"
};

string Menu_ThongKe[] =
{
    "Bạn muốn thống kê theo",
    "1.Laptop sử dụng CPU Intel",
    "2.Laptop sử dụng CPU AMD",
    "3.Laptop có RAM 16GB trở lên",
    "4.Laptop có ổ cứng SSD 512GB trở lên",
    "Mời chọn"
};

void MENU(string tieude[], int sl)
{
	system("cls");
	cout << tieude[0] << endl;
	for (int i = 1; i < sl; i++)
	{
		cout << tieude[i] << endl;
	}
}


void ReadFile(LapTop ds[], int& sl)
{
    ifstream f("Doan.txt");
    if (!f)
    {
        cout << "File Lỗi" << endl;
    }
    else
    {
        int i = 0;
        string line;
        while (getline(f, line))
        {
            stringstream ss(line);
            
            ss.getline(ds[i].maSP, 40, ',');
            ss.getline(ds[i].maCPU, 30, ',');
            ss.getline(ds[i].RAM, 15, ',');
            ss.getline(ds[i].LoaiDia, 10, ',');
            ss.getline(ds[i].DungLuongDia, 10, ',');
            ss >> ds[i].gia; ss.ignore();
            i++;
        }
        sl = i;
    }
    f.close();
}


void WriteFile(LapTop ds[], int& sl, string FileName)
{
    ofstream f(FileName+".txt", ios::out);
    if (!f)
    {
        cout << "Không thể ghi File" << endl;
    }
    else
    {
        for (int i = 0; i < sl; i++)
        {
            f << ds[i].maSP << ',';
            f << ds[i].maCPU << ',';
            f << ds[i].RAM << ',';
            f << ds[i].LoaiDia << ',';
            f << ds[i].DungLuongDia << ',';
            f << ds[i].gia << '\n';
        }
    }
    f.close();
}

void xuat1laptop(LapTop lp)
{
    cout << right << setw(26) << "Mã Sản Phẩm"
        << setw(32) << "CPU"
        << setw(25) << "RAM"
        << setw(28) << "Loại ổ đĩa"
        << setw(26) << "Dung lượng đĩa"
        << setw(31) << "Giá bán(~triệu đồng)" << endl;
    cout<<endl
        <<"  "
        << left << setw(40) << lp.maSP
        << setw(30) << lp.maCPU
        << setw(19) << lp.RAM
        << setw(20) << lp.LoaiDia
        << setw(20) << lp.DungLuongDia
        << setw(19) << lp.gia << endl;
    cout << endl;
}


//1.In danh mục laptop
void xuatDsLaptop(LapTop ds[], int sl)
{
    cout << right << setw(26) << "Mã Sản Phẩm"
        << setw(32) << "CPU"
        << setw(25) << "RAM"
        << setw(28) << "Loại ổ đĩa"
        << setw(26) << "Dung lượng đĩa"
        << setw(31) << "Giá bán(~triệu đồng)" << endl;
    for (int i = 0; i < sl; i++)
    {
        cout<<endl
            <<"  "
            << left << setw(3) << (i + 1)
            << left << setw(37) << ds[i].maSP
            << setw(30) << ds[i].maCPU
            << setw(19) << ds[i].RAM
            << setw(20) << ds[i].LoaiDia
            << setw(20) << ds[i].DungLuongDia
            << setw(19) << ds[i].gia<< endl;
        cout << endl;
    }
}

//2.Thêm Laptop
void themLaptop(LapTop &lap)
{
    //15,10,10,20
    cin.ignore();
    cout << "Nhập mã sản phẩm: ";
    cin.getline(lap.maSP, 40);
    cout << "Nhập mã CPU: ";
    cin.getline(lap.maCPU, 30);
    cout << "Nhập RAM (Gồm cả DDR3, DDR4 hay DDR5 ): ";
    cin.getline(lap.RAM, 15);
    cout << "Nhập loại đĩa [SSD(Sata-NVMe) - HDD]: ";
    cin.getline(lap.LoaiDia, 10);
    cout << "Nhập dung lượng đĩa: ";
    cin.getline(lap.DungLuongDia,10);
    cout << "Nhập giá: ";
    cin >> lap.gia;
}

//3.Xóa Laptop theo mã
int xoaLaptoptheoMaSP(LapTop ds[], int &sl, char maSP[])
{
    for (int i = 0; i < sl; i++)
    {
        if (strcmp(maSP, ds[i].maSP) == 0)
        {
            for (int j = i; j < sl - 1; j++)
            {
                ds[j] = ds[j + 1];
            }
            sl--;
            i--;
            return true;
        }
    }
    return -1;
}

//4.Chỉnh sửa thông tin Laptop
void chinhSuaLaptop(LapTop ds[], int sl)
{
    int stt;
    cout << "Nhập số thứ tự Laptop cần chỉnh sửa: ";
    cin >> stt;
    if (stt < 1 || stt > sl)
    {
        cout << "Không hợp lệ !" << endl;
    }
    else
    {
        int chon, stop;
        do
        {
            system("cls");
            MENU(Menu_ChinhSua, size(Menu_ChinhSua));
            cin >> chon;
            switch (chon)
            {
            case 1:
                system("cls");
                cout << "Nhập mã sản phẩm mới: ";
                cin.ignore();
                cin.getline(ds[stt - 1].maSP, 40);
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 2:
                system("cls");
                cout << "Nhập mã CPU mới: ";
                cin.ignore();
                cin.getline(ds[stt - 1].maCPU, 30);
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 3:
                system("cls");
                cout << "Nhập RAM mới: ";
                cin.ignore();
                cin.getline(ds[stt - 1].RAM, 15);
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 4:
                system("cls");
                cout << "Nhập loại ổ đĩa mới: ";
                cin.ignore();
                cin.getline(ds[stt - 1].LoaiDia, 10);
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 5:
                system("cls");
                cout << "Nhập dung lượng ổ mới: ";
                cin.ignore();
                cin.getline(ds[stt - 1].DungLuongDia, 10);
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 6:
                system("cls");
                cout << "Nhập giá bán mới: ";
                cin.ignore();
                cin >> ds[stt - 1].gia;
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 7:
                system("cls");
                cin.ignore(1000,'\n');
                cout << "Nhập mã sản phẩm mới: ";
      
                cin.getline(ds[stt - 1].maSP, 40); 
                cout << "Nhập CPU mới: ";
                
                cin.getline(ds[stt - 1].maCPU, 30); 
                cout << "Nhập RAM mới: "; 
                
                cin.getline(ds[stt - 1].RAM, 15); 
                cout << "Nhập loại ổ đĩa mới: "; 
                
                cin.getline(ds[stt - 1].LoaiDia, 10); 
                cout << "Nhập dung lượng đĩa mới: "; 
                
                cin.getline(ds[stt - 1].DungLuongDia, 10); 
                cout << "Nhập giá bán mới: ";
                
                cin >> ds[stt - 1].gia;
                cout << "Cập nhật thành công" << endl;
                cout << "Bấm phím bất kỳ để quay lại" << endl;
                stop = _getch();
                break;
            case 8:
                cout << "Thoát chỉnh sửa" << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
            }
        } while (chon != 8);
    }
}

// 5.Tìm kiếm - Linear Search
int Linear_Search(LapTop ds[], int sl, char ma[])
{
    for (int i = 0; i < sl; i++)
    {
        if (strcmp(ma, ds[i].maSP) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Hàm sắp xếp theo mã sản phẩm trước khi dùng BinarySearch
void sapXepTheoMaSp(LapTop ds[], int sl)
{
    for (int i = 0; i < sl - 1; i++)
    {
        for (int j = 0; j < sl - i - 1; j++)
        {
            if (strcmp(ds[j].maSP, ds[j + 1].maSP) > 0)
            {
                swap(ds[j], ds[j + 1]);
            }
        }
    }
}

//5.Tìm kiếm - BinarySearch
int Binary_Search(LapTop ds[], int sl, char ma[])
{
    int left = 0, right = sl - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        int temp = (strcmp(ma, ds[mid].maSP));
        if (temp == 0)
        {
            return mid;
        }
        else if (temp > 0)
        {
            left = mid + 1;
        }
        else if (temp < 0)
        {
            right = mid - 1;
        }
    }
    return -1;
}

//6.Tìm theo khoảng giá
int timTheoGia(LapTop ds[], int sl, float giaMin, float giaMax, int ketqua[])
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (giaMin <= ds[i].gia && ds[i].gia <= giaMax)
        {
            ketqua[dem++] = i;
        }
    }
    return dem;
}

// 7. Sắp xếp - BubbleSort
void Bubble_Sort(LapTop ds[], int sl)
{
    for (int i = 0; i < sl-1 ; i++)
    {
        for (int j = 0; j < sl -i -1; j++)
        {
            if (ds[j].gia > ds[j+1].gia) {
                swap(ds[j], ds[j+1]);
            }
        }
    }
}

//7.Sắp xếp - ShakerSort
void Shaker_Sort(LapTop ds[], int sl)
{
    int left = 0, right = sl - 1, k = sl - 1;
    while (left < right)
    {
        //Vòng lặp từ cuối về đầu - Tìm phần tử lớn nhất
        for (int i = right; i > left; i--)
        {
            if (ds[i].gia < ds[i - 1].gia) {
                swap(ds[i], ds[i - 1]);
                k = i;
            }
        }
        left = k;
        //Vòng lặp từ đầu đến cuối - Tìm phần tử nhỏ nhất
        for (int j = left; j < right; j++)
        {
            if (ds[j].gia > ds[j + 1].gia)
                swap(ds[j], ds[j + 1]);
                k = j;
        }
        right = k;
    }
}

//7.Sắp xếp - SelectionSort
void Selection_Sort(LapTop ds[], int sl)
{
    for (int i = 0; i < sl - 1; i++)
    {
        int Min = i;
        for (int j = i + 1; j < sl; j++)
        {   
            if (ds[Min].gia > ds[j].gia)
                Min = j;
        }
        swap(ds[i], ds[Min]);
    }
}

//7. Sắp xếp - InsertionSort
void Insertion_Sort(LapTop ds[], int sl)
{
    for (int i = 1; i < sl; i++)
    {
        int key = ds[i].gia;
        int j = i - 1; // j dùng để dịch các phần tử ra đằng sau để chèn phần tử thích hợp lên trước
        while (j >= 0 && ds[j].gia > key) // điều kiện để dịch
        {
            ds[j + 1] = ds[j]; // dịch vị trí trước ra vị trí sau
            j--; // Khi dịch thì giảm j đi
        } // Kết thúc while tìm đc vị trí phù hợp
        j++;
        ds[j].gia = key;
    }
}

//7. Sắp xếp - InterchangeSort
void Interchange_Sort(LapTop ds[], int sl)
{
    for (int i = 0; i < sl - 1; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (ds[i].gia > ds[j].gia)
            {
                swap(ds[i], ds[j]);
            }
        }
    }
}

//8. Thống kê
//8.1 Thống kê số laptop sử dụng chip Intel
int lapTopIntel(LapTop ds[], int sl, LapTop ketQua[]) // LapTop ketQua[] : dùng để lưu các tập con đủ điều kiện
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (strstr(ds[i].maCPU, "Intel") != nullptr) // strstr : Tìm chuỗi con trong chuỗi mẹ.
        {
            ketQua[dem++] = ds[i];
        }
    }
    return dem;
}

//8.2 Thống kê số laptop sử dụng chip AMD
int lapTopAMD(LapTop ds[], int sl, LapTop ketQua[])
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (strstr(ds[i].maCPU, "AMD") != nullptr)
        {
            ketQua[dem++] = ds[i];
        }
    }
    return dem;
}

//8.3 LapTop trên 16gb RAM
int lapTren16gbRAM(LapTop ds[], int sl, LapTop ketQua[])
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        int gtriRam = atoi(ds[i].RAM); // atoi (ASCII to integer) : Chuyển chuỗi thành số - 32GB DDR5 => 32
        if (gtriRam > 16)
        {
            ketQua[dem++] = ds[i];
        }
    }
    return dem;
}

// 8.3 Laptp có ổ cứng trên 512GB

// Khi dùng atoi thì 1TB sẽ bị hiểu là 1 => Luôn luôn không tìm được lap trên 512gb do đó điều kiện luôn là sai.
int chuyenDungLuong(string dungLuong)
{
    if (dungLuong.find("TB") != string::npos)
    {
        return stoi(dungLuong) * 1024; // 1TB => 1024
    }
    else
    {
        return stoi(dungLuong);
    }
}
int lapoCungTren512GB(LapTop ds[], int sl, LapTop ketQua[])
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        int gtriDisk = chuyenDungLuong(ds[i].DungLuongDia);
        if (gtriDisk > 512)
        {
            ketQua[dem++] = ds[i];
        }
    }
    return dem;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    LapTop ds[50];
    int stop, chon1, chon2, chon3, chon4, sl = 0;
    ReadFile(ds, sl);
    do {
        system("cls");
        MENU(Menu_Chinh, size(Menu_Chinh));
        cin >> chon1;

        switch (chon1)
        {
        case 1:
            system("cls");
            xuatDsLaptop(ds, sl);
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;

        case 2:
        {
            system("cls");
            LapTop lt;
            themLaptop(lt);
            ds[sl++] = lt;
            WriteFile(ds, sl, "Doan");
            cout << "Thêm thành công !" << endl;
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;
        }
        case 3:
        {
            system("cls");
            char maSP[40];
            cout << "Nhập mã sản phẩm cần xóa: ";
            cin.ignore();
            cin.getline(maSP, 40);
            int vitri = xoaLaptoptheoMaSP(ds, sl, maSP);
            if (vitri != -1)
            {
                cout << "Đã xóa sản phẩm" << endl;
            }
            else
            {
                cout << "Không tìm thấy mã sản phẩm này!" << endl;
            }
            WriteFile(ds, sl, "Doan");
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;
        }
        case 4:
            system("cls");
            chinhSuaLaptop(ds, sl);
            WriteFile(ds, sl, "Doan");
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;

        case 5:
            do
            {
                system("cls");
                MENU(Menu_TimKiem, size(Menu_TimKiem));
                cin >> chon2;
                switch (chon2)
                {
                case 1:
                {
                    system("cls");
                    char masp1[30];
                    cout << "Nhập mã sản phẩm cần tìm kiếm: ";
                    cin.ignore();
                    cin.getline(masp1, 30);
                    clock_t begin = clock();
                    int vitri1 = Linear_Search(ds, sl, masp1);
                    if (vitri1 != -1)
                    {
                        xuat1laptop(ds[vitri1]);
                        cout << "Đã tìm theo LinearSearch !" << endl;
                        clock_t end = clock();
                        cout << "Thời gian chạy thuật toán: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl; 
                    }
                    else
                    {
                        cout << "Không tìm thấy mã sản phẩm này !" << endl;
                    }
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }

                case 2:
                {
                    system("cls");
                    char masp2[30];
                    cout << "Nhập mã sản phẩm cần tìm kiếm: ";
                    cin.ignore();
                    cin.getline(masp2, 30);
                    sapXepTheoMaSp(ds, sl);
                    clock_t begin = clock();
                    int vitri2 = Binary_Search(ds, sl, masp2);
                    if (vitri2 != -1)
                    {
                        xuat1laptop(ds[vitri2]);
                        cout << "Đã tìm theo BinarySearch !" << endl;
                        clock_t end = clock();
                        cout << "Thời gian chạy thuật toán: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
                    }
                    else
                    {
                        cout << "Không tìm thấy mã sản phầm này !" << endl;
                    }
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }

                case 3:
                    system("cls");
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
            } while (chon2 != 3);
            break;
        case 6:
        {
            system("cls");
            int giaMin, giaMax;
            cout << "Nhập giá thấp nhất: ";
            cin >> giaMin;
            cout << "Nhập giá cao nhất: ";
            cin >> giaMax;
            int ketqua[30];
            int dem = timTheoGia(ds, sl, giaMin, giaMax, ketqua);
            if (dem > 0)
            {
                cout << "Số laptop trong khoảng giá từ " << giaMin << " đến " << giaMax<<" là" << endl;
                cout << right << setw(26) << "Mã Sản Phẩm"
                    << setw(32) << "CPU"
                    << setw(25) << "RAM"
                    << setw(28) << "Loại ổ đĩa"
                    << setw(26) << "Dung lượng đĩa"
                    << setw(31) << "Giá bán(~triệu đồng)" << endl;
                for (int i = 0; i < dem; i++)
                {
                    LapTop lp = ds[ketqua[i]];
                    cout << endl
                        << "  "
                        << left << setw(3) << (i + 1)
                        << left << setw(37) << lp.maSP
                        << setw(30) << lp.maCPU
                        << setw(19) << lp.RAM
                        << setw(20) << lp.LoaiDia
                        << setw(20) << lp.DungLuongDia
                        << setw(19) << lp.gia << endl;
                    cout << endl;
                }
            }
            else
            {
                cout << "Không có laptop trong khoảng giá này !" << endl;
            }
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;
        }
        case 7:
        {
            do
            {
                MENU(Menu_SapXep, size(Menu_SapXep));
                cin >> chon3;
                switch (chon3)
                {
                case 1:
                {
                    system("cls");
                    clock_t begin = clock();
                    Bubble_Sort(ds, sl);                   
                    xuatDsLaptop(ds, sl);
                    clock_t end = clock();
                    cout << "Thời gian chạy thuật toán: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
                    cout << "Đã sắp xếp theo BubbleSort !" << endl;
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 2:
                {
                    system("cls");
                    clock_t begin = clock();
                    Shaker_Sort(ds, sl);                  
                    xuatDsLaptop(ds, sl);
                    clock_t end = clock();
                    cout << "Thời gian chạy thuật toán: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
                    cout << "Đã sắp xếp theo SharkerSort!" << endl;
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 3:
                {
                    system("cls");
                    clock_t begin = clock();
                    Selection_Sort(ds, sl);                   
                    xuatDsLaptop(ds, sl);
                    clock_t end = clock();
                    cout << "Thời gian chạy thuật toán: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break; 
                }
                case 4:
                {
                    system("cls");
                    clock_t begin = clock();
                    Insertion_Sort(ds, sl);
                    xuatDsLaptop(ds, sl);
                    clock_t end = clock();
                    cout << "Thời gian chạy thuật toán : " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 5:
                {
                    system("cls");
                    clock_t begin = clock();
                    Interchange_Sort(ds, sl);
                    xuatDsLaptop(ds, sl);
                    clock_t end = clock();
                    cout << "Thời gian chạy thuật toán: " << (float)(end - begin) / CLOCKS_PER_SEC << "s" << endl;
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 6:
                {
                    system("cls");
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                }
            } while (chon3 != 6);
            break;
        case 8: 
        {
            
            system("cls");
            do
            {
                MENU(Menu_ThongKe, size(Menu_ThongKe));
                cin >> chon4;
                switch (chon4)
                {
                case 1:
                {
                    system("cls");
                    LapTop ketQua1[30];
                    int soIntel = lapTopIntel(ds, sl, ketQua1);
                    if (soIntel == 0)
                    {
                        cout << "Không có laptop nào sử dụng chip Intel";
                    }
                    else
                    {
                        xuatDsLaptop(ketQua1, soIntel); //ketQua là số tập con đã được lưu, soIntel là số lượng lap
                        cout << "Tìm thành công ! ";
                    }
                    
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 2:
                {
                    system("cls");
                    LapTop ketQua2[20];
                    int soAMD = lapTopAMD(ds, sl, ketQua2);
                    if (soAMD == 0)
                    {
                        cout << "Không có laptop nào sử dụng chip AMD";
                    }
                    else
                    {
                        xuatDsLaptop(ketQua2, soAMD);
                        cout << "Tìm thành công ! ";
                    }
                    
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 3:
                {
                    system("cls");
                    LapTop ketQua3[15];
                    int soRAM = lapTren16gbRAM(ds, sl, ketQua3);
                    if (soRAM == 0)
                    {
                        cout << "Không có laptop nào trên 16gb ram !";
                    }
                    else
                    {
                        xuatDsLaptop(ketQua3, soRAM);
                        cout << "Tìm thành công ! ";
                    }
                   
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;
                }
                case 4:
                {
                    system("cls");
                    LapTop ketQua4[10];
                    int soDisk = lapoCungTren512GB(ds, sl, ketQua4);
                    if (soDisk == 0)
                    {
                        cout << "Không có laptop nào có dung lượng trên 512GB !";
                    }
                    else
                    {
                        xuatDsLaptop(ketQua4, soDisk);
                        cout << "Tìm thành công ! ";
                    }
                    
                    cout << "Bấm phím bất kỳ để quay lại" << endl;
                    stop = _getch();
                    break;                                            
                }
                }
            } while (chon4 != 4);
            break;
        }
        case 9:
        {
            system("cls");
            string filename;
            cout << "Nhập tên File bạn muốn ghi: ";
            cin.ignore();
            getline(cin, filename);
            WriteFile(ds, sl, filename);
            cout << "Đã ghi File thành công !" << endl;
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;
        }
        case 10:
        {
            system("cls");
            cout << "Hẹn gặp lại" << endl;
            cout << "Bấm phím bất kỳ để quay lại" << endl;
            stop = _getch();
            break;
        }
        }
        }
    } while (chon1 != 10);
}



