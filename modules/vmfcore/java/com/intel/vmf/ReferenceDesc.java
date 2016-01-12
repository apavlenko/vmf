package com.intel.vmf;
 
public class ReferenceDesc
{
    static
    {
        System.loadLibrary("vmf");
    }
    
    protected final long nativeObj;
    
    protected ReferenceDesc (long addr)
    {
        if (addr == 0)
            throw new java.lang.UnsupportedOperationException("Native object address is NULL");
        
        nativeObj = addr;
    }
    
    public ReferenceDesc ()
	{
        nativeObj = n_ReferenceDesc ();
	}
    
    public ReferenceDesc (String refName, boolean unique, boolean custom) 
    {
        nativeObj = n_ReferenceDesc (refName, unique, custom);
    }
    
    public String getName ()
    {
        return n_getName (nativeObj);
    }
    
    public boolean isUnique ()
    {
        return n_isUnique (nativeObj);
    }
    
    public boolean isCustom ()
    {
        return n_isCustom (nativeObj);
    }
    
    @Override
    protected void finalize () throws Throwable 
    {
        if (nativeObj != 0)
            n_delete (nativeObj);
        
        super.finalize();
    }
    
    private static native long n_ReferenceDesc ();
    private static native long n_ReferenceDesc (String refName, boolean unique, boolean custom);
    private static native String n_getName (long nativeAddr);
    private static native boolean n_isUnique (long nativeObj);
    private static native boolean n_isCustom (long nativeObj);
    private static native void n_delete (long nativeAddr);
}