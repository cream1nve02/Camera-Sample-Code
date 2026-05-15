#pragma once
#include <string>
#include <cstring>
using namespace std;

// =============================================
// ImageData - 이미지 프레임 데이터를 담는 클래스
//
// [멤버 변수]
//   width, height : 이미지 해상도
//   channels      : 채널 수 (1: 흑백, 3: RGB)
//   name          : 프레임 식별자
//   data          : 픽셀 데이터 (힙에 동적 할당)
//
// [픽셀 데이터 구조]
//   1차원 배열로 저장: [R][G][B][R][G][B]...
//   특정 픽셀 접근 공식: data[(y * width + x) * channels + c]
//   전체 크기: width * height * channels (bytes)
// =============================================
class ImageData {
public:
    int width;
    int height;
    int channels;
    string name;
    unsigned char *data;  // 픽셀 데이터 포인터 (힙에 저장)

    // 생성자
    // - 이니셜라이저 리스트로 멤버변수 초기화
    // - 힙에 픽셀 데이터 공간 할당 후 0(검정)으로 초기화
    ImageData(int w, int h, int c, string n)
        : width(w), height(h), channels(c), name(n) {
        data = new unsigned char[w * h * c];
        for (int i = 0; i < w * h * c; i++) {
            data[i] = 0;
        }
    }

    // 소멸자 - 힙에 할당한 픽셀 데이터 해제
    // 배열로 할당했으므로 delete[] 사용 (delete 와 다름)
    ~ImageData() {
        delete[] data;
    }
};
