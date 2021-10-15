Pod::Spec.new do |spec|
  spec.name                   = "Mbark"
  spec.version                = "1.4.6"
  spec.summary                = "Server Driven UI."
  spec.description            = "Drag-and-Drop Flow Builder\nCompose your onboarding with an intuitive web dashboard. Customize the screens using your brand's unique design library.\n\nEasy Experimentation\nConduct tests with the flows you create. Find the flow that optimizes for key metrics like conversion, retention, and engagement.\n\nBuilt-in Funnel Analytics\nEvery flow you build ships with straightforward analytics by default. Measure the effectiveness of your onboarding at a glance."
  spec.homepage               = "https://www.mbark.co"
  spec.license                = { :type => "Commercial", :text => "Copyright 2021 mbark" }
  spec.author                 = "mbark"

  spec.source                 = { :git => "https://github.com/mbark-app-inc/mbark-sdk.git", :tag => "#{spec.version}" }

  spec.vendored_frameworks    = "Mbark.xcframework"
  spec.platform               = :ios
  spec.swift_version          = "5.0"
  spec.ios.deployment_target  = '12.0'

end
