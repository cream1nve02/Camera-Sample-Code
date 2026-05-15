#include "Camera.h"
#include <iostream>
using namespace std;

Camera::Camera() {
    cout << "[Camera] 초기화 완료" << endl;
}

// 소멸자
// - pipeline에 등록된 처리기 포인터 전부 delete
// - Camera 객체가 사라질 때 자동 호출
Camera::~Camera() {
    for (int i = 0; i < (int)pipeline.size(); i++) {
        delete pipeline[i];  // 각 처리기 힙 메모리 해제
    }
    cout << "[Camera] 종료" << endl;
}

// AddProcessor
// - 외부에서 new로 만든 처리기 포인터를 pipeline 끝에 추가
// - push_back: vector 맨 뒤에 추가 (파이썬의 append)
void Camera::AddProcessor(ImageProcessor *processor) {
    pipeline.push_back(processor);
}

// OnImageCallback
// - 프레임 수신 시 호출 (실제 카메라 SDK가 자동 호출)
// - pipeline을 순서대로 순회하며 각 처리기 실행
// - 동적 바인딩: pipeline[i]의 실제 타입에 맞는 Process 호출
void Camera::OnImageCallback(ImageData *img) {
    cout << "\n=== 프레임 수신: " << img->name << " ===" << endl;

    for (int i = 0; i < (int)pipeline.size(); i++) {
        pipeline[i]->Process(img);
    }
}
