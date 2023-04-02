# Build on MacOS

I am not a Mac person!  The procedure below was worked out with help
from a friend who develops for Mac.  This did work for me on a Mac
running macOS 12.4 (Monterey).  Note that a full Xcode install was not needed.

**Install Xcode Command Line Tools**

You can read about this
[here](https://www.freecodecamp.org/news/install-xcode-command-line-tools/).
I typed `git` and it triggered the install, which took around 20 minutes.

**Install XQuartz**

From `https://www.xquartz.org`.  Install the package.

**Install Brew**

```
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

After the install it will suggest adding some stuff to your shell profile, which I did.  Not sure if this was critical.

**Install jpeg libraries required by XForms**

```
$ brew install jpeg
$ brew install jpeg-turbo
```

**Install XForms toolkit**
From `http://xforms-toolkit.org` download `http://download.savannah.nongnu.org/releases/xforms/xforms-1.2.4.tar.gz`.
```
$ cd  xforms-1.2.4
$ ./configure
$ make
$ make install
```
(`/usr/local/lib` should now have `libjpeg.dylib` and the `libforms.dylib`)

**Build the Calculator**

```
$ cd calc-demo-xwin/src
$ make
```

When you run it with `./calc` it takes a while to fire up the X server but then it should run.
