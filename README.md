<p align="center">
  <img width="640" height="320" src="https://user-images.githubusercontent.com/641197/116633151-9e462c00-a90d-11eb-8c51-eebe3c9cffae.png">
</p>

# mbark
Welcome to the mbark framework. Native iOS app onboarding out of the box.

### Getting started
We’ll be guiding you through integrating mbark into your iOS application with a series of steps. We recommend going through them in order, although you are free to skip around.

### XCFramework
With the introduction of Xcode 12 and the M1 build target, it is no longer possible to build a single binary framework that can run on both the simulator and Apple  devices. To resolve this, Apple has introduced a new type of framework called the XCFramework.

If your company is already using Xcode 12, make sure that your dependency management system is also fully updated. Then follow the integration guide normally and you will use mbark’s XCFramework releases.

If your company has not yet started using Xcode 12, then contact us to learn how to access a non-XCFramework release.

### Decisions you'll need to make
Before you dive into integrating mbark there are a few decisions you should make to help guide your process:

- Are you integrating a new App or an existing application?
- Are you replacing an existing analytics SDK?
- Do you plan to use multiple analytics SDKs?
- What integration path makes sense for you? CocoaPods, Carthage or Manual?

Thinking about the above questions will help to define the path you will take through this documentation.

If you are starting a new application and thinking about mbark, we recommend you follow the CocoaPods integration path. This path automates many of the steps you would otherwise have to do yourself.

If you have an established application then follow the path that most closely matches the processes you are already using to build your application.

### Integration steps
Integrating any new SDK with your application can be a daunting experience. We’ve designed our documentation to guide you through the process as painlessly as possible. Following these steps will ensure you have a solid foundation for customizing and measuring your onboarding flows in production.

Regardless of the path you choose, you will be performing the following common steps to complete your integration:

### Linking mbark with your application

The mbark SDK is distributed as a framework. You will be dynamically linking this framework with your application. We support three methods for doing this:

- CocoaPods. You can easily add mbark to your PodFile and have most of this work done for you.
- Carthage. Carthage will help you keep track of mbark versions and upgrades, you will still perform much of the linking process manually.
- Swift Package Manager. Use Xcode to manage the mbark dependency for you.
- Manual. You will download the framework directly and manually link it with your project.

We’ve broken out the integration for each method individually below. You only need to look at the section relevant to your application and can safely skip the other 3.

Make sure to continue reading after linking to learn how to open and use the mbark dashboard.

#### CocoaPods
CocoaPods is a dependency management system for iOS; You’ll work with CocoaPods from the command line via the `pod` command, and you’ll configure it via a PodFile at the root of your project.

If you are starting a new project, first initialize the project and repo using Xcode. Then, run `pod init` from the command line and a PodFile will be created for you.

If you have an existing project, then use your existing PodFile for the following steps:

- Open your PodFile in a text editor and add this entry to your target: "pod 'mbark-sdk'". Make sure to include mbark in any other variants, such as QA or Dev builds.
- Save and close your PodFile.
- Run the command `pod update` and your new dependency will be automatically integrated.
- From now on your will open the xcworkspace associated with your project and not the older xcproject file.

### Keeping mbark up to date
#### Updating using CocoaPods
If you've aleady integrated mbark with your application using Cocoapods, it will be simple to update mbark with each new version.

When a new version is released, simply run the command line utility `pod update Mbark` in the root of your project and Cocoapods will do the rest.

To verify an update was successful, build and run your application.

### Connect to the mbark dashboard
Before you start recording onboarding data, let's connect your app to the dashboard.

#### Import mbark

Let’s start by importing the mbark module. Open your program’s `AppDelegate.swift` class or equivalent.

At the top of the file where you see the other import statements, add one for mbark.

```swift
import Mbark
```
Now we’re going to add a couple of new files to our project. mbark has many optional features and configuration options that you may want to use. It is best to start your integration with an mbark configuration file so it’s easy to add those options later.

Make a new file in the root of your project called `Mbark-Info.plist` and ensure that it is included in your target.

For now, you can just add one entry to this file: "API_KEY". Be sure to fill in the value with the key you received from the mbark team.

Make another new file in the root of your project called `Mbark.json` and ensure that it is included in your target. Using the following as a template, add the flow ID, flow name, and flow revision you received from the mbark team to this file.

```json
{
  "flowID": "FLOW_ID",
  "flowDevID": "FLOW_NAME",
  "flowRevision": 1,
  "enabled": false,
  "steps": []
}
```

#### Add an initialization call
Next, inside your main startup function (usually ApplicationDidFinishLaunching) add the following code to start mbark. mbark does not perform any onboarding tracking or other configuration actions until this call is made.

```swift
Mbark.initialize()
```
##### A Note On Placing the Start Call
It is important that this call be made as soon as possible in the lifecycle of your application to ensure we can configure your complete onboarding flow. 

#### Marking the start of your onboarding flow
We're ready to mark the start of your onboarding flow. Tell mbark to start tracking the flow in the `viewDidLoad()` method of the first `UIViewController` in your onboarding. Like so:

```swift
override func viewDidLoad() {
  super.viewDidLoad()
  Mbark.trackFlowStart()
 }
```

You can assign this view controller an mbark ID. This will help the mbark SDK automatically track view events for this step. Register other interactive elements in this view controller you would like to automatically track events on. In the example below we give two buttons their own mbark IDs. Tap events will now be automatically recorded by mbark. UI components that have assigned mbark IDs may also be configured remotely.

```swift
override func viewDidLoad() {
  super.viewDidLoad()
  Mbark.trackFlowStart()
  setMbarkId("welcome")
  signUpButton.setMbarkId("sign_up")
  signInButton.setMbarkId("sign_in")
 }
```

Prefer a more traditional events tracking interface? Use mbark's explicit tracking methods instead:

```swift
@IBAction func onTap(_ sender: UIButton) {
  Mbark.trackTap(step: "welcome", component: "sign_up", data: MbarkEventData(name: "carousel_index", value: carousel.currentIndex))
}
```
Continue through your onboarding flow marking important steps and components with either assigned mbark IDs or tracking calls.

#### Marking the end of your onboarding flow
Make sure to track the end of your onboarding flow by calling `Mbark.trackFlowEnd()`. You have the option to add this call in the `viewDidLoad()` method of your landing screen `UIViewController`. Flow end events will only be tracked during active onboarding sessions.

```swift
override func viewDidLoad() {
  super.viewDidLoad()
  Mbark.trackFlowEnd()
 }
```

##### A note on ensuring an onboarding session ends

`Mbark.trackFlowEnd()` is used to track onboarding abandonment. This is the number of users who never complete onboarding. To correctly track this it is critical that all onboarding paths end with a call to `Mbark.trackFlowEnd()` eventually. 

### Build and Run Your Application
Alright, you’re ready to build and run your application! If you encounter any errors, please get in touch with the mbark team. We can help you out.

### Trigger onboarding session uploads
The mbark SDK is designed to efficiently manage and upload all onboarding analytics. Short collections of events are packaged up and sent to the mbark dashboard every few minutes. If a user backgrounds the app during onboarding, mbark will immediately upload any queued events. A local copy of events are also persisted to the device. In the event of an app crash, the event flow can be recreated and added to when the user relaunches and resumes onboarding.

To trigger an early session upload, simply send your application to the background and then foreground it again. Typically the SDK will be given sufficient time to upload the session when it is backgrounded.

Congratulations! At this point you’ve completed a basic integration of the mbark SDK. mbark is already collecting interesting data from your application. You can view this data by browsing the mbark dashboard online.
