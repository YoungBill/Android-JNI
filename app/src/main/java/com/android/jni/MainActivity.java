package com.android.jni;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity {

    private TextView mTv;

    static {
        System.loadLibrary("JNITest");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTv = findViewById(R.id.text);
    }

    public void onClick(View view) {
        String text = helloJNI();
        mTv.setText(text);
    }

    public native String helloJNI();
}
