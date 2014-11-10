LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS) 
LOCAL_SRC_FILES := Log.c

LOCAL_CFLAGS := -std=gnu99
LOCAL_MODULE := libavmputils
LOCAL_ARM_MODE := arm

include $(BUILD_STATIC_LIBRARY)
