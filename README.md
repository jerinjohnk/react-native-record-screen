# react-native-record-screen

A screen record module for React Native.

- Support iOS >= 11.0 (Simulator is not work)

- Support Android
  - minSdkVersion = 26
  - compileSdkVersion = 29
  - targetSdkVersion = 29
  - use [HBRecorder](https://github.com/HBiSoft/HBRecorder)

## Installation

### iOS

```sh
npm install react-native-record-screen
```

add info.pilot

```
<key>NSCameraUsageDescription</key>
<string>Please allow use of camera</string>
<key>NSMicrophoneUsageDescription</key>
<string>Please allow use of microphone</string>
```

pod install

```sh
npx pod-install
```

### Android

AndroidManifest.xml

```
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
<uses-permission android:name="android.permission.WRITE_INTERNAL_STORAGE" />
<uses-permission android:name="android.permission.RECORD_AUDIO" />
<uses-permission android:name="android.permission.FOREGROUND_SERVICE" />
```

## Usage

### Recording full screen

```js
import RecordScreen from 'react-native-record-screen';

// recording start
RecordScreen.startRecording().catch((error) => console.error(error));

// recording stop
const res = await RecordScreen.stopRecording().catch((error) =>
  console.warn(error)
);
if (res) {
  const url = res.result.outputURL;
}
```

### Setting microphone

default true.

```js
// mic off, 
RecordScreen.startRecording({ 
      mic: false,  
      videoBitRate: 1024 * 1024, // default value is 1000*1000
      videoFrameRate: 24, // default value is 20
  }).catch((error) =>
  console.error(error)
);

// recording stop
const res = await RecordScreen.stopRecording().catch((error) =>
  console.warn(error)
);
if (res) {
  const url = res.result.outputURL;
}
```

### Clean Sandbox

```js
RecordScreen.clean();
```

## About video cropping

The video cropping feature has been removed.
Video crops will be created as another library.

## Android device fix

In some phones, such as Redmi, Vivo, etc., if the `Movies` folder doesn't exist, the video file is not saved. Since the library won't create the folder by itself, unlike Samsung for android, you can check if the folder exists before starting the screen record.

```
import RNFetchBlob from 'rn-fetch-blob';
import { Platform } from 'react-native';

const checkAndroidMoviesExist = () => {
    if (Platform.OS === 'ios') {
      return;
    }

    const {dirs} = RNFetchBlob.fs;
    let pathToSave = `${dirs.SDCardDir}/Movies`;
    pathToSave = pathToSave.replace(' ', '');

    RNFetchBlob.fs
      .exists(pathToSave)
      .then((exist) => {
        if (!exist) {
          RNFetchBlob.fs
            .mkdir(pathToSave)
            .then(() => {
              console.log('At mkdir', pathToSave);
            })
            .catch((err) => {
              console.log('At mkdir error', pathToSave, err);
            });
        }
      })
      .catch((error) => {});
  };
```

## License

MIT
