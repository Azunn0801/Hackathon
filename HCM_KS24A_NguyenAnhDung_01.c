#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, n, sum = 0;
    int del_pos;
    int arr[9999];
    int isPrime, ifPrime = 0;

    do
    {
        printf("\n==========MENU==========\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra cac gia tri phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong tat ca phan tu\n");
        printf("5. Them phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep theo thu tu giam dan\n");
        printf("8. Tim phan tu\n");
        printf("9. In toan bo so nguyen to trong mang\n");
        printf("10. Sap xep mang theo thu tu tang dan\n");
        printf("0. Thoat chuong trinh\n");
        printf("Moi ban nhap lua chon (1 - 10): ");
        scanf("%d", &choice);
        int min_num = 999999;
        int max_num = -999999;
        int find_num, flag = 0, idx;
        switch(choice)
        {
        case 1:
            printf("\nNhap so phan tu trong mang: ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
            {
                printf("\nNhap arr[%d]: ", i);
                scanf("%d", arr + i);
            }
            break;
        case 2:
            for(int i = 0; i < n; i++)
            {
                printf("\narr[%d] = %d", i, arr[i]);
            }
            break;
        case 3:
            for(int i = 0; i < n; i++)
            {
                if(arr[i] > max_num)
                {
                    max_num = arr[i];
                }
                if(arr[i] < min_num)
                {
                    min_num = arr[i];
                }
            }
            printf("\nGia tri nho nhat la: %d", min_num);
            printf("\nGia tri lon nhat la: %d", max_num);
            break;
        case 4:
            for(int i = 0; i < n; i++)
            {
                sum += arr[i];
            }
            printf("\nTong cac phan tu la %d", sum);
            break;
        case 5:
            printf("\nNhap so muon them vao tai arr[%d]: ", n);
            scanf("%d", &arr[n]);
            n++;
            break;
        case 6:
            printf("\nNhap vi tri can xoa: ");
            scanf("%d", &del_pos);
            while(del_pos < 0 || del_pos >= n)
            {
                printf("\nVi tri khong hop le, vui long nhap lai: ");
                scanf("%d", &del_pos);
            }
            n--;
            for(int i = 0; i <= del_pos; i++)
            {
                if(i == del_pos)
                {
                    for(int j = i; j < n; j++)
                    {
                        arr[j] = arr[j + 1];
                    }
                }
                break;
            }
            break;
        case 7:
            for(int i = 0; i < n - 1; i++)
            {
                for(int j = 0; j < n - i - 1; j++)
                {
                    if(arr[j] < arr[j + 1])
                    {
                        int tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            printf("\nMang sau khi duoc sap xep: \n");
            for(int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            break;
        case 8:
            printf("\nNhap so can tim: ");
            scanf("%d", &find_num);
            for(idx = 0; idx < n; idx++)
            {
                if(arr[idx] == find_num)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                printf("\nSo %d duoc tim thay o vi tri %d", find_num, idx);
            }
            else
            {
                printf("\nSo %d khong ton tai trong mang", find_num);
            }
            break;
        case 9:
            ifPrime = 0;
            for(idx = 0; idx < n; idx++)
            {
                if(arr[idx] < 2)
                {
                    isPrime = 0;
                }
                else
                {
                    isPrime = 1;
                    for(int j = 2; j * j <= arr[idx]; j++)
                    {
                        if(arr[idx] % j == 0)
                        {
                            isPrime = 0;
                            break;
                        }
                    }
                    if(isPrime == 1)
                    {
                        printf("%d ", arr[idx]);
                        ifPrime = 1;
                    }
                }
            }
            if(ifPrime == 0)
            {
                printf("\nKhong co so nguyen to ton tai");
            }
            break;
        case 10:
            printf("\nMang sau khi duoc sap xep: ");
            for(int i = 0; i < n - 1; i++)
            {
                int min_idx = i;
                for(int j = i + 1; j < n; j++)
                {
                    if(arr[j] < arr[min_idx])
                    {
                        min_idx = j;
                    }
                }
                int tmp = arr[i];
                arr[i] = arr[min_idx];
                arr[min_idx] = tmp;
            }
            for(int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
        }
    }
    while(choice != 0);
    return 0;
}
