# SLATEC

These files are from the SLATEC Common Mathematical Library, Version 4.1, July 1993.

### Installation using Conda

The most direct way to install the code is through the conda package manager.
If you have conda installed,  
(1) activate an environment in you wish to use to install SLATEC, and  
(2) run the install command:
```
conda install -c auto-mech slatec
```

If you do not have a preferred Conda environment set up, an empty environment with no packages can be created and activated with the following commands
```
conda create --name myenv
conda activate myenv
```
where `myenv` should be replaced with your preferred name for the environment.

Alternatively, we also recommend building our own pre-set Auto-Mech environment, which includes SLATEC and the codes which use it. This environment can be created and activated with the commands:
```
conda env create auto-mech/amech-env
conda activate amech-env
```

If your Conda commands are not functioning, you may need to iniliatize Conda via the command
```
. /path/to/conda.sh
```
which places Conda executables in your PATH. The specific location of conda.sh depends on the Conda install.


If you do not have conda, it can be installed using the shell script
`debug/install-conda.sh`.

### Building from source without Conda

Run build.sh, which uses cmake to compile SLATEC:
```
bash build.sh
```

Note that the results of the `make install` in build.sh will depend on your system setup.


## Notice 

Author:  
Giuseppe Borzi'  
e-mail: etana@tiscalinet.it  
http://web.tiscalinet.it/gborzi  
fax: +39 1782235968  
Assistant Professor at the Univ. of Messina - Italia

License:  
General Public License. Slatec is 'Freely distributable' as they say.

For further details, see <http://www.netlib.org/slatec/>.
