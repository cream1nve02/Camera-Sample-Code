#include "BinaryProcessor.h"
#include <iostream>
using namespace std;

BinaryProcessor::BinaryProcessor(unsigned char threshold)
    : threshold(threshold) {}

// Process 구현
// - 흑백 이미지(channels=1) 기준
// - 픽셀값 > threshold → 255 (흰색)
// - 픽셀값 <= threshold → 0  (검정)
void BinaryProcessor::Process(ImageData *img) {
    cout << "[Binary] threshold: " << (int)threshold << " 적용" << endl;

    int size = img->width * img->height;  // 흑백이라 channels=1

    for (int i = 0; i < size; i++) {
        // 삼항연산자: 조건 ? 참일때값 : 거짓일때값
        img->data[i] = (img->data[i] > threshold) ? 255 : 0;
    }
}
