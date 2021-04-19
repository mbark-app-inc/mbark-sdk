Pod::Spec.new do |spec|
  spec.name                   = "mbark-sdk"
  spec.version                = "0.0.12"
  spec.summary                = "App Onboarding Out of the Box."
  spec.description            = "We help teams get the right customers onboarded with a toolset that allows them to experiment with user flows and deploy changes instantly."
  spec.homepage               = "https://www.mbark.co"
  spec.license                = { :type => "Commercial", :text => "Copyright 2021 mbark" }
  spec.author                 = "mbark"

  spec.source                 = { :git => "https://github.com/mbark-app-inc/mbark-sdk.git", :tag => "#{spec.version}" }

  spec.vendored_frameworks    = "Mbark.xcframework"
  spec.platform               = :ios
  spec.swift_version          = "5.0"
  spec.ios.deployment_target  = '12.0'

end
