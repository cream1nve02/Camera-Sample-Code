#include "ResizeProcessor.h"
#include <iostream>
#include <cstring>
using namespace std;

// 생성자
// - 이니셜라이저 리스트로 목표 해상도 저장
// - 구현할 내용이 없어서 {} 비워둠
ResizeProcessor::ResizeProcessor(int targetW, int targetH)
    : targetW(targetW), targetH(targetH) {}

// Process 구현
// - img 포인터로 원본 ImageData 직접 수정
// - 픽셀 데이터를 새 크기로 재할당
void ResizeProcessor::Process(ImageData *img) {
    cout << "[Resize] " << img->width << "x" << img->height
         << " → " << targetW << "x" << targetH << endl;

    // 기존 픽셀 데이터 해제 후 새 크기로 재할당
    delete[] img->data;
    img->width  = targetW;
    img->height = targetH;
    img->data   = new unsigned char[targetW * targetH * img->channels];
    memset(img->data, 0, targetW * targetH * img->channels);
}
