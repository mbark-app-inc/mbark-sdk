# mbark
Welcome to the mbark framework. Native iOS app onboarding out of the box.

### Getting Started
We’ll be guiding you through integrating mbark into your iOS application with a series of steps. We recommend going through them in order, although you are free to skip around.

### XCFramework
With the introduction of Xcode 12 and the M1 build target, it is no longer possible to build a single binary framework that can run on both the simulator and Apple  devices. To resolve this, Apple has introduced a new type of framework called the XCFramework.

If your company is already using Xcode 12, make sure that your dependency management system is also fully updated. Then follow the integration guide normally and you will use mbark’s XCFramework releases.

If your company has not yet started using Xcode 12, then contact us to learn how to access a non-XCFramework release.

### Decisions You'll Need To Make
Before you dive into integrating mbark there are a few decisions you should make to help guide your process:

- Are you integrating a new App or an existing application?
- Are you replacing an existing analytics SDK?
- Do you plan to use multiple analytics SDKs?
- What integration path makes sense for you? CocoaPods, Carthage or Manual?

Thinking about the above questions will help to define the path you will take through this documentation.

If you are starting a new application and thinking about mbark, we recommend you follow the CocoaPods integration path. This path automates many of the steps you would otherwise have to do yourself.

If you have an established application then follow the path that most closely matches the processes you are already using to build your application.

### Integration Steps
Integrating any new SDK with your application can be a daunting experience. We’ve designed our documentation to guide you through the process as painlessly as possible. Following these steps will ensure you have a solid foundation for customizing and measuring your onboarding flows in production.

Regardless of the path you choose, you will be performing the following common steps to complete your integration:

### Linking mbark with your Application

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

#### Carthage
To do...

#### Swift Package Manager
To do...

#### Manual
To do...
