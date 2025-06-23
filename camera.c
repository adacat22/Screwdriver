#include "screwdriver.h"

int gridMoveSpeed = 50;

void update_camera(void) {
    if (mode == MODE_NORMAL) {
        if (IsKeyPressed(KEY_V)) {
            mode = MODE_VIEW;
            viewMode = VIEW_3D;
            DisableCursor();
        }
    } else if (mode == MODE_VIEW) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            mode = MODE_NORMAL;
            EnableCursor();
        }
        if (IsKeyPressed(KEY_G)) {
            viewMode = (viewMode == VIEW_3D) ? VIEW_2D_GRID : VIEW_3D;
        }
	
        if (viewMode == VIEW_3D) {
            UpdateCamera(&camera, CAMERA_FIRST_PERSON);
            Vector3 moveDelta = {0};
            if (IsKeyDown(KEY_W)) moveDelta.z -= gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_S)) moveDelta.z += gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_A)) moveDelta.x -= gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_D)) moveDelta.x += gridMoveSpeed * GetFrameTime();
            /*camera.target.x += moveDelta.x;
            camera.target.z += moveDelta.z;
            camera.position.x += moveDelta.x;
            camera.position.z += moveDelta.z;*/

        } 
	if(viewMode == VIEW_2D_GRID) {
            UpdateCamera(&camera, CAMERA_FIRST_PERSON);
            Vector3 moveDelta = {0};
            if (IsKeyDown(KEY_W)) moveDelta.z -= gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_S)) moveDelta.z += gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_A)) moveDelta.x -= gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_D)) moveDelta.x += gridMoveSpeed * GetFrameTime();
            camera.target.x += moveDelta.x;
            camera.target.z += moveDelta.z;
            camera.position.x += moveDelta.x;
            camera.position.z += moveDelta.z;
	}else {
            Vector3 moveDelta = {0};
            if (IsKeyDown(KEY_W)) moveDelta.z -= gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_S)) moveDelta.z += gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_A)) moveDelta.x -= gridMoveSpeed * GetFrameTime();
            if (IsKeyDown(KEY_D)) moveDelta.x += gridMoveSpeed * GetFrameTime();
            camera.target.x += moveDelta.x;
            camera.target.z += moveDelta.z;
            camera.position.x += moveDelta.x;
            camera.position.z += moveDelta.z;
        }
    }
}
